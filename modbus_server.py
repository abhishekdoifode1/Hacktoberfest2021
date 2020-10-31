import modbus_tk
import modbus_tk.defines as cst
import modbus_tk.modbus_tcp as modbus_tcp
import modbus_tk.utils
import time
import sys
import datetime

#IP_SERVER = '127.0.0.1'
#PORT = 502
SLAVE_ID = 1
STARTING_ADDRESS = 200
RANGE_PARAM = 500

def timeServer():
    now = datetime.datetime.now()
    #listTime = [now.year,now.month,now.day,now.hour,now.minute,now.second]
    listTime = [now.second]
    return listTime

logger = modbus_tk.utils.create_logger(name="console", record_format="%(message)s")
# CREATE server
server = modbus_tcp.TcpServer()  # DEFAULT PORT=502

if __name__=="__main__":
    try:
        logger.info("running...")
        logger.info("Enter Ctrl+C for closing ModbusServer")

        server.start()
        slave_1 = server.add_slave(SLAVE_ID)
        #slave_1.add_block("a", cst.ANALOG_INPUTS, STARTING_ADDRESS, RANGE_PARAM)
        slave_1.add_block("a", cst.HOLDING_REGISTERS, STARTING_ADDRESS, RANGE_PARAM)
        slave_1.set_values("a", STARTING_ADDRESS, range(RANGE_PARAM))

        while True:
            timeServerList = timeServer()
            for address in range(STARTING_ADDRESS, RANGE_PARAM+1):
                slave_1.set_values("a", address, (int)(timeServerList[0]))
            """
            slave_1.set_values("a", 200, (int)(timeServerList[0]))
            slave_1.set_values("a", 201, (int)(timeServerList[1]))
            slave_1.set_values("a", 202, (int)(timeServerList[2]))
            slave_1.set_values("a", 203, (int)(timeServerList[5]))
            slave_1.set_values("a", 204, (int)(timeServerList[4]))
            slave_1.set_values("a", 205, (int)(timeServerList[3]))
            slave_1.set_values("a", 206, 0)
            
            alive_2 = slave_1.get_values("a", 200, 7)
            print("Clock computer", alive_2)
            """
            time.sleep(1)
            

    except modbus_tk.modbus_tcp.TcpServer as expTcpServer:
        logger.error("%s- Code=%d" % (expTcpServer, expTcpServer.get_exception_code()))

    finally:
        logger.info("destory")
        # STOP
        server.stop()
