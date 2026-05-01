"""
============================================================
  Daily Expense Tracker - CLI Tool
  Author : Aryan Maharjan
  Date   : 2026
  Desc   : A command-line tool to log, view, filter,
           and summarise daily spending, with a budget
           alert and ASCII progress bar.
============================================================
"""

# ── Standard library imports ─────────────────────────────
import os


# ══════════════════════════════════════════════════════════
#  HELPER UTILITIES
# ══════════════════════════════════════════════════════════

def clear_screen():
    """Clear the terminal for a cleaner UI experience."""
    os.system("cls" if os.name == "nt" else "clear")


def separator(char="─", width=50):
    """Print a horizontal divider line."""
    print(char * width)


def format_currency(amount):
    """
    Format a numeric amount as a currency string with
    exactly two decimal places.  e.g. 10.5  →  Rs.10.50
    """
    return f"Rs.{amount:.2f}"


# ══════════════════════════════════════════════════════════
#  ASCII PROGRESS BAR  (Bonus)
# ══════════════════════════════════════════════════════════

def progress_bar(spent, budget, bar_width=20):
    """
    Build and print a text-based progress bar that shows
    how much of the monthly budget has been consumed.

    Parameters
    ----------
    spent     : float  -total expenses so far
    budget    : float  -monthly budget set by the user
    bar_width : int    -number of characters in the bar
    """
    if budget <= 0:
        print("  No budget set — progress bar unavailable.")
        return

    ratio      = min(spent / budget, 1.0)   # cap at 100 %
    filled     = int(ratio * bar_width)
    empty      = bar_width - filled
    bar        = "#" * filled + "-" * empty
    percentage = ratio * 100

    print(f"  Budget used : [{bar}] {percentage:.1f}%")
    print(f"  Spent       : {format_currency(spent)}  /  "
          f"Budget: {format_currency(budget)}")


# ══════════════════════════════════════════════════════════
#  CORE EXPENSE FUNCTIONS
# ══════════════════════════════════════════════════════════

def add_expense(expenses):
    """
    Prompt the user for expense details (item name, cost,
    category) and append a new dictionary to the expenses
    list.  Validates that the cost is a positive number.

    Parameters
    ----------
    expenses : list - the shared in-memory expense store
    """
    separator()
    print("ADD NEW EXPENSE")
    separator()

    # ── Item name ─────────────────────────────────────────
    item = input("  Item name      : ").strip()
    if not item:
        print("Item name cannot be empty. Returning to menu.")
        return

    # ── Cost (with input validation) ──────────────────────
    while True:
        raw_amount = input("  Cost (Rs.)     : ").strip()
        try:
            amount = float(raw_amount)
            if amount <= 0:
                raise ValueError("Amount must be positive.")
            break                               # valid input → exit loop
        except ValueError:
            print("Please enter a valid positive number (e.g. 250 or 19.99).")

    # ── Category ──────────────────────────────────────────
    VALID_CATEGORIES = ["Food", "Transport", "Entertainment", "Bills", "Other"]
    print("\n  Categories: " + " | ".join(f"{i+1}. {c}"
        for i, c in enumerate(VALID_CATEGORIES)))
    while True:
        cat_input = input("  Choose (1-5)   : ").strip()
        if cat_input.isdigit() and 1 <= int(cat_input) <= len(VALID_CATEGORIES):
            category = VALID_CATEGORIES[int(cat_input) - 1]
            break
        print("Enter a number between 1 and 5.")

    # ── Build and store the record ────────────────────────
    expense = {
        "item"     : item,
        "amount"   : amount,
        "category" : category,
    }
    expenses.append(expense)

    print(f"\nAdded: {item} — {format_currency(amount)} [{category}]")


def view_all(expenses):
    """
    Print every recorded expense in a neat, numbered table.
    Shows item name, category, and formatted cost.

    Parameters
    ----------
    expenses : list - the shared in-memory expense store
    """
    separator()
    print("ALL EXPENSES")
    separator()

    if not expenses:
        print("  No expenses recorded yet.")
        return

    # Column headers
    print(f"  {'#':<4} {'Item':<22} {'Category':<15} {'Amount':>10}")
    separator("·")

    for idx, exp in enumerate(expenses, start=1):
        print(f"  {idx:<4} {exp['item']:<22} {exp['category']:<15} "
              f"{format_currency(exp['amount']):>10}")

    separator("·")
    total = sum(e["amount"] for e in expenses)
    print(f"  {'':4} {'':22} {'TOTAL':<15} {format_currency(total):>10}")


def total_summary(expenses, budget):
    """
    Calculate and display the grand total of all expenses.
    Also shows a budget alert and ASCII progress bar when a
    budget has been set.

    Parameters
    ----------
    expenses : list  - the shared in-memory expense store
    budget   : float - monthly budget (0 if not set)
    """
    separator()
    print("TOTAL SUMMARY")
    separator()

    if not expenses:
        print("  No expenses to summarise.")
        return

    total = sum(e["amount"] for e in expenses)
    print(f"\n  Total expenses : {format_currency(total)}")
    print(f"  Items logged   : {len(expenses)}\n")

    # ── ASCII progress bar (Bonus) ─────────────────────────
    progress_bar(total, budget)

    # ── Budget alert (Bonus) ──────────────────────────────
    if budget > 0 and total > budget:
        separator("!")
        overshoot = total - budget
        print(f"BUDGET EXCEEDED by {format_currency(overshoot)}!")
        print("     Please review your spending.")
        separator("!")
    elif budget > 0:
        remaining = budget - total
        print(f"\nUnder budget — {format_currency(remaining)} remaining.")


def view_by_category(expenses):
    """
    Ask the user for a category name and display only the
    expenses that belong to that category, along with a
    sub-total for that category.

    Parameters
    ----------
    expenses : list - the shared in-memory expense store
    """
    separator()
    print("VIEW BY CATEGORY")
    separator()

    if not expenses:
        print("  No expenses recorded yet.")
        return

    # Collect all distinct categories present in the data
    categories = sorted({e["category"] for e in expenses})
    print("  Available categories: " + ", ".join(categories))

    chosen = input("\n  Enter category name: ").strip().capitalize()

    # Filter the list
    filtered = [e for e in expenses if e["category"].lower() == chosen.lower()]

    if not filtered:
        print(f"  No expenses found for category '{chosen}'.")
        return

    print(f"\n  Expenses in '{chosen}':")
    separator("·")
    print(f"  {'#':<4} {'Item':<25} {'Amount':>10}")
    separator("·")

    for idx, exp in enumerate(filtered, start=1):
        print(f"  {idx:<4} {exp['item']:<25} {format_currency(exp['amount']):>10}")

    separator("·")
    sub_total = sum(e["amount"] for e in filtered)
    print(f"  {'':4} {'Sub-total':<25} {format_currency(sub_total):>10}")


# ══════════════════════════════════════════════════════════
#  MAIN MENU LOOP
# ══════════════════════════════════════════════════════════

def print_menu():
    """Render the main navigation menu to the screen."""
    separator("═")
    print("  💰  DAILY EXPENSE TRACKER")
    separator("═")
    print("  1. Add Expense")
    print("  2. View All Expenses")
    print("  3. Total Summary")
    print("  4. View by Category")
    print("  5. Exit")
    separator("═")


def get_budget():
    """
    Prompt the user for a monthly budget at start-up.
    Returns 0 if the user skips or enters an invalid value.

    Returns
    -------
    float - the monthly budget (0 means 'not set')
    """
    separator()
    print("MONTHLY BUDGET SETUP")
    separator()
    print("  Enter your monthly budget to enable budget alerts")
    print("  and the spending progress bar.")
    print("  (Press ENTER to skip)\n")

    raw = input("  Monthly budget (Rs.) : ").strip()
    if not raw:
        print("  Budget skipped — alerts disabled.\n")
        return 0.0

    try:
        budget = float(raw)
        if budget <= 0:
            raise ValueError
        print(f"  Budget set to {format_currency(budget)}\n")
        return budget
    except ValueError:
        print("Invalid input — budget set to 0 (alerts disabled).\n")
        return 0.0


def main():
    """
    Entry point of the application.
    Initialises the expense list and budget, then runs the
    main while-loop menu until the user chooses to exit.
    """
    # ── In-memory data store ──────────────────────────────
    expenses = []   # list of dicts: {item, amount, category}

    # ── One-time budget setup ─────────────────────────────
    clear_screen()
    budget = get_budget()

    # ── Main interactive loop ─────────────────────────────
    while True:
        print_menu()
        choice = input("  Select an option (1-5): ").strip()

        if choice == "1":
            add_expense(expenses)

        elif choice == "2":
            view_all(expenses)

        elif choice == "3":
            total_summary(expenses, budget)

        elif choice == "4":
            view_by_category(expenses)

        elif choice == "5" or choice.lower() == "exit":
            separator("═")
            print("Thank you for using Expense Tracker. Goodbye!")
            separator("═")
            break

        else:
            print("Invalid option. Please enter a number between 1 and 5.")

        # Pause so the user can read output before the menu redraws
        input("\n  Press ENTER to continue...")
        clear_screen()


# ── Script entry point ────────────────────────────────────
if __name__ == "__main__":
    main()
    
# Project 2:Dataset Analysis
# https://colab.research.google.com/drive/1_87pkF7nK7znuIMMSdxT-x96tCesLwH_?usp=sharing