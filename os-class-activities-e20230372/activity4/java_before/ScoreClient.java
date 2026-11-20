
import java.io.*;
import java.net.*;

public class ScoreClient {
    private static final int PORT = 9011;

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
            System.out.println(
                "Usage: java ScoreClient <server_ip> <student_name>"
            );
            return;
        }

        String serverIp = args[0];
        String name = args[1];

        try (Socket socket = new Socket(serverIp, PORT);
             PrintWriter output = new PrintWriter(
                 socket.getOutputStream(), true);
             BufferedReader input = new BufferedReader(
                 new InputStreamReader(socket.getInputStream()))) {

            output.println(name);

            String response = input.readLine();
            System.out.println(response);
        }
    }
}
