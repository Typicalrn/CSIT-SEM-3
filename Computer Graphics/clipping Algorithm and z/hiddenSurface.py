# to demonstrate and implement hidden surface removal using z-buffer algorithm
# Z-Buffer Algorithm - Python Simulation
# Run: python zbuffer_simulation.py

import numpy as np
import matplotlib.pyplot as plt

# ----- Setup -----
MAXX, MAXY = 500, 400
zbuffer     = np.full((MAXY, MAXX), 9999.0)
framebuffer = np.zeros((MAXY, MAXX, 3), dtype=np.uint8)
framebuffer[:] = [30, 30, 30]          # dark background
RED   = [220, 50,  50]
GREEN = [50,  200, 80]

# ----- Z-Buffer core logic -----
def draw_pixel_z(x, y, z, color):
    """Draw pixel only if z is smaller (closer) than stored depth."""
    if 0 <= x < MAXX and 0 <= y < MAXY:
        if z < zbuffer[y][x]:
            zbuffer[y][x] = z
            framebuffer[y][x] = color

def draw_rect_z(x1, y1, x2, y2, z, color):
    """Fill rectangle using Z-buffer depth testing."""
    for y in range(y1, y2 + 1):
        for x in range(x1, x2 + 1):
            draw_pixel_z(x, y, z, color)

# ----- Draw two overlapping objects -----
draw_rect_z(80,  80,  270, 210, 10.0, RED)    # Object 1: RED, z=10 (farther)
draw_rect_z(160, 140, 350, 270,  5.0, GREEN)  # Object 2: GREEN, z=5 (nearer)

# ----- Prepare depth map for display -----
depth_display = np.where(zbuffer == 9999.0, np.nan, zbuffer)

# ----- Plot side by side -----
fig, axes = plt.subplots(1, 2, figsize=(13, 5))
fig.patch.set_facecolor('#1a1a2e')

# Frame buffer panel
ax1 = axes[0]
ax1.imshow(framebuffer, origin='upper')
ax1.set_title("Frame Buffer Output\n(What the screen shows)", color='white', fontsize=13)
ax1.axis('off')
ax1.annotate('RED\nz=10\n(farther)', xy=(130, 120), color='white', fontsize=9, ha='center',
             bbox=dict(boxstyle='round,pad=0.3', fc='#dc3232', alpha=0.8))
ax1.annotate('GREEN\nz=5\n(nearer)', xy=(300, 230), color='white', fontsize=9, ha='center',
             bbox=dict(boxstyle='round,pad=0.3', fc='#22aa44', alpha=0.8))
ax1.annotate('GREEN hides RED\nhere (overlap)', xy=(210, 170), color='white', fontsize=8, ha='center',
             xytext=(370, 75), arrowprops=dict(arrowstyle='->', color='yellow'),
             bbox=dict(boxstyle='round,pad=0.3', fc='#333355', alpha=0.9))

# Depth map panel
ax2 = axes[1]
cmap = plt.cm.gray_r.copy()
cmap.set_bad(color='#1a1a2e')
im = ax2.imshow(depth_display, cmap=cmap, vmin=4, vmax=11, origin='upper')
ax2.set_title("Z-Buffer (Depth Map)\n(Darker = closer to viewer)", color='white', fontsize=13)
ax2.axis('off')
cbar = plt.colorbar(im, ax=ax2, fraction=0.03, pad=0.02)
cbar.set_label('Depth (z)', color='white', fontsize=10)
cbar.ax.tick_params(colors='white')
cbar.set_ticks([5, 10])
cbar.set_ticklabels(['5 (close)', '10 (far)'])
ax2.annotate('z=5\n(darker)', xy=(255, 200), color='white', fontsize=9, ha='center',
             bbox=dict(boxstyle='round', fc='#222', alpha=0.85))
ax2.annotate('z=10\n(lighter)', xy=(120, 130), color='white', fontsize=9, ha='center',
             bbox=dict(boxstyle='round', fc='#555', alpha=0.85))

plt.suptitle('Z-Buffer Algorithm — Hidden Surface Removal',
             color='white', fontsize=14, fontweight='bold', y=1.01)
plt.tight_layout()
plt.savefig('zbuffer_output.png', dpi=130, bbox_inches='tight', facecolor='#1a1a2e')
print("Output saved to zbuffer_output.png")
plt.show()

