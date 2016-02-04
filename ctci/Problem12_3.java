package ctci;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;
import java.util.Scanner;


// Given many (4 billion) integers (of unspecified size), find an integer not in that list,
// using only 1MB of memory.
// Assume positive 31-bit integers.
public class Problem12_3 {

	public static final int INT_SIZE = 32;
	public static final int MEM_SIZE = (int)Math.pow(2, 10);
	public static final int NUM_BUCKETS = MEM_SIZE / (INT_SIZE * 2);
	public static final int BUCKET_SIZE =  (int)Math.pow(2, 32) / NUM_BUCKETS;
	public static final int NUM_TEST_INTS = 4000000;
	
	public static int[] lows = new int[NUM_BUCKETS];
	public static int[] highs = new int[NUM_BUCKETS];
	public static boolean[] wasUpdated = new boolean[NUM_BUCKETS];
	
	public static void setInput() throws IOException{
		Random rand = new Random();
		FileWriter pw = new FileWriter(new File("input123.txt"));
		for(int i = 0; i < NUM_TEST_INTS; i++){
			String s = Integer.toString(
					Math.abs(rand.nextInt())
					);
			//System.out.println(s);
			pw.write(s);
			pw.write("\n");
		}
		pw.close();
	}
	
	public static boolean verify(int n) throws FileNotFoundException{
		Scanner scanner = new Scanner(new File("input123.txt"));
		while(scanner.hasNextInt()){
			int k = scanner.nextInt();
			if(k == n){
				// Value was a duplicate
				return false;
			}
		}
		return true;
		
	}
	
	public static int getIndex(int input){
		return (int)Math.floor(input / BUCKET_SIZE);
	}
	
	public static void main(String[] args){

		try {
			try {
				System.out.println("Generating input...");
				setInput();
				System.out.println("Finished generating input.");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			Scanner scanner = new Scanner(new File("input123.txt"));
			for(int i = 0; i < NUM_BUCKETS; i++){
				lows[i] = -1;
				highs[i] = -1;
				wasUpdated[i] = false;
			}
			scanner.close();
			
			// Were any of the buckets updated in a single complete pass?
			boolean anyUpdate = true;
			int numPasses = 0;
			while(anyUpdate){
				numPasses++;
				anyUpdate = false;
				scanner = new Scanner(new File("input123.txt"));
				// On new pass, none are updated yet
				for(int i = 0; i < NUM_BUCKETS; i++){
					wasUpdated[i] = false;
				}				
				while(scanner.hasNextInt()){
					//System.out.println("Read an integer");
					int n = scanner.nextInt();
					int index = getIndex(n);
					// If the bucket is uninitialized, fill it with new entry
					if(lows[index] == -1 || highs[index] == -1){
						lows[index] = n;
						highs[index] = n;
						wasUpdated[index] = true;
						anyUpdate = true;
						continue;
					}else if(n + 1 == lows[index]){
						lows[index] = n;
						wasUpdated[index] = true;
						anyUpdate = true;
						continue;
					}else if(n - 1 == highs[index]){
						highs[index] = n;
						wasUpdated[index] = true;
						anyUpdate = true;
						continue;
					}
				}
				scanner.close();
			}
			System.out.println("We ended on pass " + Integer.toString(numPasses));
			
			
			for(int i = 0; i < NUM_BUCKETS; i++){
				System.out.println("Bucket " + Integer.toString(i) + ": " + Integer.toString(lows[i]) + " to " + Integer.toString(highs[i]));
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}
