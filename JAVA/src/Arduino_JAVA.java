import com.fazecast.jSerialComm.SerialPort;

/**
 * Simple application that is part of an tutorial.
 * The tutorial shows how to establish a serial connection between a Java and Arduino program with the help of an USB-to-TTL Module.
 * @author Michael Schoeffler (www.mschoeffler.de)
 *
 */
public class Arduino_JAVA {
    public static void main(String[] args) throws InterruptedException {
        SerialPort sp = SerialPort.getCommPort("COM5"); // device name TODO: must be changed
        sp.setComPortParameters(9600, 8, 1, 0); // default connection settings for Arduino
        sp.setComPortTimeouts(SerialPort.TIMEOUT_WRITE_BLOCKING, 0, 0); // block until bytes can be written

        if (sp.openPort()) {
            System.out.println("Port is open :)");
        } else {
            System.out.println("Failed to open port :(");
            return;
        }

        while(true){
            if (sp.bytesAvailable() > 0){
                byte[] buffer = new byte[sp.bytesAvailable()];
                sp.readBytes(buffer, buffer.length); // lees de beschikbare bytes in de buffer

                System.out.println(new String(buffer));
            }
        }
    }
}
