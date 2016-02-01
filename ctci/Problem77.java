package ctci;

import java.util.Scanner;

public class Problem77 {

	public static boolean is357(int value){
		while(value % 3 == 0){
			value = value / 3;
		}
		while(value % 5 == 0){
			value = value / 5;
		}
		while(value % 7 == 0){
			value = value / 7;
		}
		if(value == 1 ){
			return true;
		}else{
			return false;
		}
	}
	
	// Simplest method, proceed until we find a nth value
	public static int find357(int n){
		int value = -1;
		int counter = 0;
		int i = 0;;
		while(counter < n){
			i++;
			if(is357(i)){
				counter++;
				value = i;
				System.out.println(Integer.toString(i));
			}
		}
		return value;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println("Enter nth term:");
		Scanner scanner = new Scanner(System.in);		
		int n = scanner.nextInt();
		scanner.close();
		
		System.out.println(Integer.toString(find357(n)));
		
	}

}
