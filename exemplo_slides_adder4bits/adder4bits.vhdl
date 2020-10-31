library ieee;
use ieee.numeric_bit.all;

entity adder4bits is
   port (
      a:         in  bit_vector(3 downto 0);
	   b:         in  bit_vector(3 downto 0);
	   sum:       out bit_vector(3 downto 0);
	   carry_out: out bit
   );
end adder4bits;

architecture adder4bits_arch of adder4bits is
   signal sum_c: bit_vector(4 downto 0);  -- sinal interno que captura o carry
begin
   sum_c <= bit_vector(unsigned('0' & a) + unsigned('0' & b));  -- operandos e resultado com 5 bits (1 a mais que as entradas e saída)
   sum   <= sum_c(3 downto 0);      -- associa a saída 'sum' aos 4 bits menos significativos do sinal interno 'sum_c'
   carry_out <= sum_c(4);           -- associa a saída 'carry_out' ao bit mais significativo do sinal interno 'sum_c'
end adder4bits_arch;