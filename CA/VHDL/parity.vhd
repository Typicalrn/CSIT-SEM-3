library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Parity Generator (Even Parity, 4-bit data)
entity parity_gen is
  Port (
    D     : in  STD_LOGIC_VECTOR(3 downto 0);
    P_bit : out STD_LOGIC
  );
end parity_gen;

architecture Behavioral of parity_gen is
begin
  P_bit <= D(0) xor D(1) xor D(2) xor D(3);
end Behavioral;

-- Parity Checker
entity parity_checker is
  Port (
    D_with_P : in  STD_LOGIC_VECTOR(4 downto 0);  -- 4 data + 1 parity
    Error    : out STD_LOGIC
  );
end parity_checker;

architecture Behavioral of parity_checker is
begin
  Error <= D_with_P(0) xor D_with_P(1) xor D_with_P(2)
           xor D_with_P(3) xor D_with_P(4);
end Behavioral;
