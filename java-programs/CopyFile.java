import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

/**
 * This file will copy contents of a file from one file to another file.
 */
public class CopyFile {
    public static void main(String args[]) throws IOException {
        FileInputStream inputStream = null;
        FileOutputStream outputStream = null;

        // Provide File locations
        String inputFileLocation = "input.txt";
        String outputFileLocation = "output.txt";

        try {
            // Create Input and Output streams
            inputStream = new FileInputStream(inputFileLocation);
            outputStream = new FileOutputStream(outputFileLocation);

            // Read the data from Input file in bytes and write each byte to output file
            int dataByte;
            while ((dataByte = inputStream.read()) != -1) {
                outputStream.write(dataByte);
            }
        } finally {
            // Always close the streams to avoid memory leaks
            closeResources(inputStream, outputStream);
        }
    }

    /**
     * Close the Streams
     *
     * @param inputStream
     * @param outputStream
     */
    private static void closeResources(FileInputStream inputStream, FileOutputStream outputStream) throws IOException {
        if (inputStream != null) {
            inputStream.close();
            inputStream = null;
        }
        if (outputStream != null) {
            outputStream.close();
            outputStream = null;
        }
    }
}
