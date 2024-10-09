import java.io.*;
import java.util.Scanner;
class file {

    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        if (System.getProperty("ONLINE_JUDGE") == null) {
            try {
                System.setOut(new PrintStream(
                                  new FileOutputStream("output.txt")));
                read = new Scanner(new File("input.txt"));
            } catch (Exception e) {
            }
        }
        int testcase = read.nextInt();
        while (testcase > 0) {
            solve();
            testcase -= 1;
        }

    }
    public static void solve() {
        
    }
}
