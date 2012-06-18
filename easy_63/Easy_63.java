/*
Created by: Thomas Hewton-Waters
reddit.com/r/dailyprogrammer

Write a procedure called reverse(N, A), where N is an integer and A 
is an array which reverses the N first items in the array and leaves the rest intact.
For instance, if N = 3 and A = [1,2,3,4,5], then reverse(N,A) will 
modify A so that it becomes [3,2,1,4,5], because the three first 
items, [1,2,3], have been reversed. Here are a few other examples:
reverse(1, [1, 2, 3, 4, 5])      -> A = [1, 2, 3, 4, 5]
reverse(2, [1, 2, 3, 4, 5])      -> A = [2, 1, 3, 4, 5]
reverse(5, [1, 2, 3, 4, 5])      -> A = [5, 4, 3, 2, 1]
reverse(3, [51, 41, 12, 62, 74]) -> A = [12, 41, 51, 62, 74]
So if N is equal to 0 or 1, A remains unchanged, and if N is equal 
to the size of A, all of A gets flipped.
Try to write reverse() so that it works in-place; that is, it 
uses only a constant amount of memory in addition to the list A 
itself. This isn't necessary, but it is recommended.
*/

import java.util.Arrays;

public class Easy_63
{
	private final int N = 2;
	private int[] arr = { 1, 2, 3, 4, 5 };

	public int[] getArr()
	{
		return arr;
	}

	public void reverse()
	{
		if( N > arr.length || N <= 1 )
			return;

		for( int i = 0; i < N / 2; i++ )
		{
			int temp = arr[i];
			arr[i] = arr[N - 1 - i];
			arr[N - 1 - i] = temp;
		}
	}

	public static void main( String[] args )
	{
		Easy_63 e63 = new Easy_63();
		System.out.println( Arrays.toString( e63.getArr() ) );

		e63.reverse();

		System.out.println( Arrays.toString( e63.getArr() ) );
	}
}