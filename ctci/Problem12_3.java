package ctci;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


// Given many (4 billion) integers (of unspecified size), find an integer not in that list,
// using only 1MB of memory.
// Assume positive 31-bit integers.
public class Problem12_3 {

	public static final int INT_SIZE = 32;
	public static final int MEM_SIZE = (int)Math.pow(2, 10);
	public static final int NUM_BUCKETS = MEM_SIZE / (INT_SIZE * 2);
	public static final int BUCKET_SIZE =  (int)Math.pow(2, 32) / NUM_BUCKETS;
	
	public static int[] lows = new int[NUM_BUCKETS];
	public static int[] highs = new int[NUM_BUCKETS];
	
	public static int getIndex(int input){
		return (int)Math.floor(input / BUCKET_SIZE);
	}
	
	public static void main(String[] args){
		System.out.println("Enter file containing many integers: ");
		Scanner scanner = new Scanner(System.in);	
//		String filename = scanner.nextLine();
		scanner.close();	
		
		try {
			scanner = new Scanner(new File("input123.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		for(int i = 0; i < BUCKET_SIZE; i++){
			lows[i] = -1;
			highs[i] = -1;
		}
		
		while(scanner.hasNextInt()){
			int n = scanner.nextInt();
			int index = getIndex(n);
			// If the bucket is uninitialized, fill it with new entry
			if(lows[index] == -1 || highs[index] == -1){
				lows[index] = n;
				highs[index] = n;
				continue;
			}else if(n + 1 == lows[index]){
				lows[index] = n;
				continue;
			}else if(n - 1 == highs[index]){
				highs[index] = n;
				continue;
			}
		}
			
		
		for(int i = 0; i < BUCKET_SIZE; i++){
			System.out.println("Bucket " + Integer.toString(i) + Integer.toString(lows[i]) + " to " + Integer.toString(highs[i]));
		}
		
	}
}
