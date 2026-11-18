/* PoolDemo.java — Using a fixed thread pool */
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class PoolDemo {

    static class WorkerTask implements Runnable {
        private final int taskId;

        WorkerTask(int taskId) {
            this.taskId = taskId;
        }

        @Override
        public void run() {
            String threadName = Thread.currentThread().getName();

            System.out.printf(
                "Task %d: started on %s%n",
                taskId, threadName
            );

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }

            System.out.printf(
                "Task %d: completed on %s%n",
                taskId, threadName
            );
        }
    }

    public static void main(String[] args)
            throws InterruptedException {

        System.out.println(
            "Main: creating a thread pool with 2 workers...\n"
        );

        ExecutorService pool = Executors.newFixedThreadPool(2);

        for (int i = 1; i <= 6; i++) {
            pool.submit(new WorkerTask(i));
        }

        pool.shutdown();

        pool.awaitTermination(1, TimeUnit.MINUTES);

        System.out.println("\nMain: all tasks completed.");
    }
}
