library ieee;
use ieee.numeric_bit.all;
###############################                  ULA DONE BY NATHAN LUZ                   ###################### 
entity alu1bit is
  port (
    a, b, less, cin: in bit;
    result, cout, set, overflow: out bit;
    ainvert, binvert: in bit;
    operation: in bit_vector(1 downto 0)
  );
end entity;

architecture alu1_arch of alu1bit is
  signal op_a, op_b : bit;
  signal sum : bit;
  signal carry_out : bit;
  begin
    op_a <= a xor ainvert;
    op_b <= b xor binvert;
    sum <= ((not cin) and (op_a xor op_b)) or (cin and (not (op_a xor op_b)));
    set <= sum;
    carry_out <= (op_a and op_b) or (op_b and cin) or (op_a and cin);
    cout <= carry_out;
    overflow <= cin xor carry_out;
  with operation select result <=
      (op_a and op_b) when "00",
      (op_a or op_b) when "01",
      sum when "10",
      less when "11";
      --(not a) and b when "11";
  end architecture;
