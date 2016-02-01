package ctci;

import java.util.Scanner;

public class Problem77 {

	public static int findODP(int n){
		int value = -1;
		int counter = 0;
		int i = 0;;
		while(counter < n){
			i++;
			int temp = i;
			while(temp % 3 == 0){
				temp = temp / 3;
			}
			while(temp % 5 == 0){
				temp = temp / 5;
			}
			while(temp % 7 == 0){
				temp = temp / 7;
			}
			if(temp == 1){
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
		
		System.out.println(Integer.toString(findODP(n)));
		
	}

}
