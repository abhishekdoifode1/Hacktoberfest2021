library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use ieee.NUMERIC_STD.all;
entity ALU is
  generic ( 
     constant N: natural := 1  
    );
  
    Port (
    A, B     : in  STD_LOGIC_VECTOR(7 downto 0);  
    ALU_Sel  : in  STD_LOGIC_VECTOR(3 downto 0);  
    ALU_Out   : out  STD_LOGIC_VECTOR(7 downto 0); 
    Carryout : out std_logic
    );
end ALU; 
architecture Behavioral of ALU is

signal ALU_Result : std_logic_vector (7 downto 0);
signal tmp: std_logic_vector (8 downto 0);

begin
   process(A,B,ALU_Sel)
 begin
  case(ALU_Sel) is
  when "0000" =>
   ALU_Result <= A + B ; 
  when "0001" =>
   ALU_Result <= A - B ;
  when "0010" =>
   ALU_Result <= std_logic_vector(to_unsigned((to_integer(unsigned(A)) * to_integer(unsigned(B))),8)) ;
  when "0011" =>
   ALU_Result <= std_logic_vector(to_unsigned(to_integer(unsigned(A)) / to_integer(unsigned(B)),8)) ;
  when "0100" =>
   ALU_Result <= std_logic_vector(unsigned(A) sll N);
  when "0101" =>
   ALU_Result <= std_logic_vector(unsigned(A) srl N);
  when "0110" =>
   ALU_Result <= std_logic_vector(unsigned(A) rol N);
  when "0111" =>
   ALU_Result <= std_logic_vector(unsigned(A) ror N);
  when "1000" =>
   ALU_Result <= A and B;
  when "1001" =>
   ALU_Result <= A or B;
  when "1010" =>
   ALU_Result <= A xor B;
  when "1011" => 
   ALU_Result <= A nor B;
  when "1100" => 
   ALU_Result <= A nand B;
  when "1101" => 
   ALU_Result <= A xnor B;
  when "1110" => 
   if(A>B) then
    ALU_Result <= x"01" ;
   else
    ALU_Result <= x"00" ;
   end if; 
  when "1111" => 
   if(A=B) then
    ALU_Result <= x"01" ;
   else
    ALU_Result <= x"00" ;
   end if;
  when others => ALU_Result <= A + B ; 
  end case;
 end process;
 ALU_Out <= ALU_Result;
 tmp <= ('0' & A) + ('0' & B);
 Carryout <= tmp(8);
end Behavioral;