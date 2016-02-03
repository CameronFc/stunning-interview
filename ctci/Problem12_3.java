package ctci;

import java.util.Scanner;


// Given many (4 billion) integers (of unspecified size), find an integer not in that list,
// using only 1MB of memory.
public class Problem12_3 {

	public static final int INT_SIZE = 32;
	public static final int MEM_SIZE = (int)Math.pow(2, 10);
	public static final int NUM_BUCKETS = MEM_SIZE / (INT_SIZE * 2);
	public static final int BUCKET_SIZE =  (int)Math.pow(2, 32) / NUM_BUCKETS;
	
	public static int getIndex(int input){
		return (int)Math.floor(input / BUCKET_SIZE);
	}
	
	public static void main(String[] args){
		System.out.println("Enter file containing many integers: ");
		Scanner scanner = new Scanner(System.in);		
		int n = scanner.nextInt();
		scanner.close();		
		
		System.out.println(Integer.toString(getIndex(n)));
		
		
	}
}
