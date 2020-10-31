entity adder4bits_tb is
end entity;

architecture adder4bits_tb_arch of adder4bits_tb is

   -- Declara o componente do DUT
   component adder4bits is
      port (
        	a:         in  bit_vector(3 downto 0);
	    	b:         in  bit_vector(3 downto 0);
	    	sum:       out bit_vector(3 downto 0);
	    	carry_out: out bit
      );
   end component;

   signal a_in, b_in, s_out: bit_vector(3 downto 0);
   signal c_out: bit;

begin
  
   DUT: adder4bits port map (a => a_in, b => b_in, sum => s_out, carry_out => c_out);
   
   gerador_estimulos: process
   begin
      a_in <= "0000";
	  b_in <= "0000";
	  wait for 1 ns;  -- espera estabilizar e verifica a saída
	  assert (c_out & s_out = "00000") report "Fail 0+0" severity error;
	  
	  a_in <= "0001";
	  b_in <= "0001";
	  wait for 1 ns;  -- espera estabilizar e verifica a saída
	  assert (c_out & s_out = "00010") report "Fail 1+1" severity error;

	  a_in <= "1000";
	  b_in <= "1000";
	  wait for 1 ns;  -- espera estabilizar e verifica a saída
	  assert (c_out & s_out = "10000") report "Fail 8+8" severity error;

	  a_in <= "1111";
	  b_in <= "0001";
	  wait for 1 ns;  -- espera estabilizar e verifica a saída
	  assert (c_out & s_out = "10000") report "Fail F+1" severity error;

	  a_in <= "1110";
	  b_in <= "0111";
	  wait for 1 ns;  -- espera estabilizar e verifica a saída
	  assert (c_out & s_out = "10101") report "Fail E+7" severity error;

	  a_in <= "0111";
	  b_in <= "0011";
	  wait for 1 ns;  -- espera estabilizar e verifica a saída
	  assert (c_out & s_out = "01010") report "Fail 7+3" severity error;

	  a_in <= "1100";
	  b_in <= "0101";
	  wait for 1 ns;  -- espera estabilizar e verifica a saída
	  assert (c_out & s_out = "10001") report "Fail C+5" severity error;

	  -- Limpa entradas (opcional)
	  a_in <= "0000";
	  b_in <= "0000";
	  
	  -- Informa fim do teste
	  assert false report "Test done." severity note;	  
	  wait;  -- pára a execução do simulador, caso contrário este process é reexecutado indefinidamente.
   end process;
   

end adder4bits_tb_arch;