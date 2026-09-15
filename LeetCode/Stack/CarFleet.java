import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class CarFleet {
    public int carFleet(int target, int[] position, int[] speed) {
        if (position.length != speed.length) {
            return 0;
        }

        int n = position.length;

        int[][] cars = new int[n][2];
        for (int i = 0; i < n; i++) {
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }

        Arrays.sort(cars, (a, b) -> Integer.compare(b[0], a[0]));

        double[] time = new double[n];
        for (int i = 0; i < n; i++) {
            time[i] = (double) (target - cars[i][0]) / cars[i][1];
        }

        Deque<Double> fleets = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            if (!fleets.isEmpty() && time[i] <= fleets.peek()) {
                continue;
            } else {
                fleets.push(time[i]);
            }
        }

        return fleets.size();
    }

    static void main() {
        int[] position = {4,1,0,7}, speed = {2,2,1,1};

        System.out.println(new CarFleet().carFleet(10, position, speed));

    }
}
