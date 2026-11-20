
import java.io.*;
import java.net.*;

public class ScoreServerNoSync {
    private static final int PORT = 9011;
    private static final String FILE_NAME = "shared_score.txt";

    private static int updateScore(String name) throws Exception {
        int score = 0;

        try (BufferedReader reader =
                 new BufferedReader(new FileReader(FILE_NAME))) {
            score = Integer.parseInt(reader.readLine().trim());
        }

        Thread.sleep(200);

        score++;

        try (FileWriter writer = new FileWriter(FILE_NAME)) {
            writer.write(score + "\n");
        }

        System.out.println(name + " updated score to " + score);
        return score;
    }

    private static void handleClient(Socket socket) {
        try (Socket client = socket;
             BufferedReader input = new BufferedReader(
                 new InputStreamReader(client.getInputStream()));
             PrintWriter output = new PrintWriter(
                 client.getOutputStream(), true)) {

            String name = input.readLine();
            int score = updateScore(name);
            output.println("Score is now " + score);

        } catch (Exception e) {
            System.err.println("Client error: " + e.getMessage());
        }
    }

    public static void main(String[] args) throws Exception {
        ServerSocket server = new ServerSocket(PORT);

        System.out.println(
            "Java no-sync server running on port " + PORT
        );

        while (true) {
            Socket socket = server.accept();
            new Thread(() -> handleClient(socket)).start();
        }
    }
}
