import java.util.ArrayList;
import java.util.Scanner;
import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
public class alexis {

    static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader( 
                new InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() { return Integer.parseInt(next()); } 
  
        long nextLong() { return Long.parseLong(next()); } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try { 
                if(st.hasMoreTokens()){ 
                    str = st.nextToken("\n"); 
                } 
                else{ 
                    str = br.readLine(); 
                } 
            } 
            catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 

    public static void solve() {
        FastReader scanner = new FastReader(); 
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        ArrayList<String> ans = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            int m = scanner.nextInt();
            int prev = -1;
            int maxii = -1000000000;
            for (int j = 0; j < m; j++) {
                int x = scanner.nextInt();
                if (prev == -1) {
                    prev = x;
                    continue;
                }
                maxii = Math.max(prev - x, maxii);
                prev = x;
            }
            if (maxii <= a) {
                ans.add(s);
            }
        }

        System.out.println(ans.size());
        for (String x : ans) {
            System.out.println(x);
        }
    }

    public static void main(String[] args) {
        solve();
    }
}
