package ctci;

import java.util.Random;


// Given an array consisting of integer from 0 to N: N <= 32000; N unknown; duplicates possible;
// Print all duplicates.
public class Problem12_4 {

	public static void main(String[] args){
		
		final int UP_BOUND = 32000;
		final int ARR_SIZE = 64000;
		int[] array = new int[ARR_SIZE];
		for(int i = 0; i < UP_BOUND; i++){
			array[i] = i;
		}
		
		Random rand = new Random();
		for(int i = UP_BOUND; i < ARR_SIZE; i++){
			array[i] = rand.nextInt(UP_BOUND);
		}
		
		final int MEM_SIZE = (int) Math.pow(2, 12);
		
		boolean[] table = new boolean[MEM_SIZE];

		// Iterate over sections of the range 0 -> 32000 of size MEM_SIZE
		for(int i = 0; i < (UP_BOUND / MEM_SIZE) + 1; i++){
			// Start off not having seen any duplicates in this small range.
			for(int m = 0; m < MEM_SIZE; m++){
				table[m] = false;
			}
			// Pass over the input array
			for(int index = 0; index < ARR_SIZE; index++){
				// Check if the value we are looking at in the input is handled by this sub-range
				if(array[index] / MEM_SIZE == i){
					int offset = array[index] % MEM_SIZE;
					// Duplicate was found
					if(table[offset]){
						System.out.println("Element(" + Integer.toString(index) + ") was a duplicate");
					}else{
						table[offset] = true;
					}
				}
			}
		}
	}
}
