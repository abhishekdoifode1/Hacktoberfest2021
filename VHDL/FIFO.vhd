Library IEEE;
USE IEEE.Std_logic_1164.all;

entity fifo_mem is 
   port(
      data_out : out std_logic_vector(7 downto 0);    
      fifo_full, fifo_empty, fifo_threshold, 
      fifo_overflow, fifo_underflow: out std_logic;
      clk :in std_logic;  
      rst_n: in std_logic;  
      wr :in  std_logic;
      rd: in std_logic;
      data_in: in std_logic_vector(7 downto 0)
   );
end fifo_mem;
architecture Behavioral of fifo_mem is  
component write_pointer
   port(
      wptr : out std_logic_vector(4 downto 0);    
   fifo_we: out std_logic;
      clk :in std_logic;  
   rst_n: in std_logic;  
      wr :in  std_logic;
   fifo_full: in std_logic
   );
end component;
component read_pointer
   port(
      rptr : out std_logic_vector(4 downto 0);    
   fifo_rd: out std_logic;
      clk :in std_logic;  
   rst_n: in std_logic;  
      rd :in  std_logic;
   fifo_empty: in std_logic
   );
end component;
component memory_array
   port(
      data_out : out std_logic_vector(7 downto 0);    
   rptr: in  std_logic_vector(4 downto 0);    
      clk :in std_logic;  
   fifo_we: in std_logic;  
      wptr :in  std_logic_vector(4 downto 0);    
   data_in: in std_logic_vector(7 downto 0)
   );
end component;
component status_signal
   port(
      fifo_full, fifo_empty, fifo_threshold: out std_logic;    
   fifo_overflow, fifo_underflow : out std_logic;    
      wr, rd, fifo_we, fifo_rd,clk,rst_n :in std_logic;  
      wptr, rptr: in  std_logic_vector(4 downto 0)
   );
end component;
  signal empty, full: std_logic;    
  signal wptr,rptr: std_logic_vector(4 downto 0);
  signal fifo_we,fifo_rd: std_logic;    
begin  

 write_pointer_unit: write_pointer port map 
      (   
          wptr => wptr, 
       fifo_we=> fifo_we, 
       wr=> wr,  
       fifo_full => full,
       clk => clk,
       rst_n => rst_n
      );
 read_pointer_unit: read_pointer port map 
      (
       rptr => rptr,
       fifo_rd => fifo_rd,
       rd => rd ,
       fifo_empty => empty,
       clk => clk,
       rst_n => rst_n
      );
 memory_array_unit: memory_array port map 
      (
       data_out => data_out,
       data_in => data_in,
       clk => clk,
       fifo_we => fifo_we,
       wptr => wptr,
       rptr => rptr
      );
 status_signal_unit: status_signal port map 
      (
       fifo_full => full,
       fifo_empty => empty,
       fifo_threshold => fifo_threshold,
       fifo_overflow => fifo_overflow, 
       fifo_underflow => fifo_underflow,
       wr => wr, 
       rd => rd, 
       fifo_we => fifo_we,
       fifo_rd => fifo_rd,
       wptr => wptr,
       rptr => rptr,
       clk => clk,
       rst_n => rst_n
      );
 fifo_empty <= empty;
 fifo_full <= full;
end Behavioral; 
Library IEEE;
USE IEEE.Std_logic_1164.all;
USE ieee.std_logic_arith.all;  
USE ieee.std_logic_unsigned.all;  

entity status_signal is 
   port(
      fifo_full, fifo_empty, fifo_threshold: out std_logic;    
   fifo_overflow, fifo_underflow : out std_logic;    
      wr, rd, fifo_we, fifo_rd,clk,rst_n :in std_logic;  
      wptr, rptr: in  std_logic_vector(4 downto 0)
   );
end status_signal;
architecture Behavioral of status_signal is  
  signal fbit_comp, overflow_set, underflow_set: std_logic;
  signal pointer_equal: std_logic;
  signal pointer_result:std_logic_vector(4 downto 0);
  signal full, empty: std_logic;
begin  
 
  fbit_comp <= wptr(4) xor rptr(4);
  pointer_equal <= '1' 
  when (wptr(3 downto 0) = rptr(3 downto 0)) else '0';
  pointer_result <= wptr - rptr;
  overflow_set <= full and wr;
  underflow_set <= empty and rd;
  full <= fbit_comp and  pointer_equal;
  empty <= (not fbit_comp) and  pointer_equal;
  fifo_threshold <=  '1' 
  when (pointer_result(4) or pointer_result(3))='1' else '0';
  fifo_full <= full;
  fifo_empty <= empty;
  process(clk,rst_n)
  begin
  if(rst_n='0') then 
 fifo_overflow <= '0';
  elsif(rising_edge(clk)) then 
     if ((overflow_set='1')and (fifo_rd='0')) then 
  fifo_overflow <='1';
  elsif(fifo_rd='1') then 
  fifo_overflow <= '0';
  end if;
  end if;
  end process;
  
  process(clk,rst_n)
  begin
  if(rst_n='0') then  
 fifo_underflow <='0';
  elsif(rising_edge(clk)) then
    if((underflow_set='1')and(fifo_we='0')) then
       fifo_underflow <='1';
    elsif(fifo_we='1') then 
      fifo_underflow <='0';
 end if;
   end if;
  end process;
end Behavioral; 

Library IEEE;
USE IEEE.Std_logic_1164.all;
USE ieee.numeric_std.ALL;

entity memory_array is 
   port(
      data_out : out std_logic_vector(7 downto 0);    
   rptr: in  std_logic_vector(4 downto 0);    
      clk :in std_logic;  
   fifo_we: in std_logic;  
      wptr :in  std_logic_vector(4 downto 0);    
   data_in: in std_logic_vector(7 downto 0)
   );
end memory_array;
architecture Behavioral of memory_array is  
 type mem_array is array (0 to 15) of std_logic_vector(7 downto 0);
 signal data_out2: mem_array;
begin  
 
 process(clk)
 begin 
     if(rising_edge(clk)) then
   if(fifo_we='1') then 
          data_out2(to_integer(unsigned(wptr(3 downto 0)))) <= data_in; 
   end if;
  end if;      
 end process;  
 data_out <= data_out2(to_integer(unsigned(rptr(3 downto 0))));
 
end Behavioral; 

Library IEEE;
USE IEEE.Std_logic_1164.all;
USE ieee.std_logic_arith.all;  
USE ieee.std_logic_unsigned.all; 

entity read_pointer is 
   port(
      rptr : out std_logic_vector(4 downto 0);    
   fifo_rd: out std_logic;
      clk :in std_logic;  
   rst_n: in std_logic;  
      rd :in  std_logic;
   fifo_empty: in std_logic
   );
end read_pointer;
architecture Behavioral of read_pointer is  
signal re: std_logic;
signal read_addr:std_logic_vector(4 downto 0);    
begin  
 rptr <= read_addr;
 fifo_rd <= re ;
 re <= (not fifo_empty) and rd;
 process(clk,rst_n)
 begin 
     if(rst_n='0') then 
   read_addr <= (others => '0');
     elsif(rising_edge(clk)) then
   if(re='1') then 
    read_addr <= read_addr + "00001"; 
   end if;
  end if;      
 end process;  
end Behavioral; 

Library IEEE;
USE IEEE.Std_logic_1164.all;
USE ieee.std_logic_arith.all;  
USE ieee.std_logic_unsigned.all; 
  
entity write_pointer is 
   port(
      wptr : out std_logic_vector(4 downto 0);    
   fifo_we: out std_logic;
      clk :in std_logic;  
   rst_n: in std_logic;  
      wr :in  std_logic;
   fifo_full: in std_logic
   );
end write_pointer;
architecture Behavioral of write_pointer is  
signal we: std_logic;
signal write_addr:std_logic_vector(4 downto 0);    
begin  
 fifo_we <= we;
 we <= (not fifo_full) and wr;
 wptr <= write_addr;
 process(clk,rst_n)
 begin 
     if(rst_n='0') then 
   write_addr <= (others => '0');
     elsif(rising_edge(clk)) then
   if(we='1') then 
    write_addr <= write_addr + "00001"; 
   end if;
  end if;      
 end process;  
end Behavioral; 