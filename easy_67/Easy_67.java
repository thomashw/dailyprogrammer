/*
As we all know, when computers do calculations or store numbers, 
they don't use decimal notation like we do, they use binary notation. 
So for instance, when a computer stores the number 13, it doesn't store 
"1" and "3", it stores "1101", which is 13 in binary.
But more than that, when we instruct it to store an integer, we usually 
tell it to store it in a certain datatype with a certain length. For 
(relatively small) integers, that length is usually as 32 bits, or four 
bytes (also called "one word" on 32-bit processors). So 13 isn't really 
stored as "1101", it's stored as "00000000000000000000000000001101".
If we were to reverse that bit pattern, we would get 
"10110000000000000000000000000000", which written in decimal becomes "2952790016".
Write a program that can do this "32-bit reverse" operation, so when given the number 13, 
it will return 2952790016.
Note: just to be clear, for all numbers in this problem, we are using unsigned 
32 bit integers.
*/

import java.util.Arrays;
import java.util.Scanner;

public class Easy_67
{
	private int _number;
	private int[] _binary;

	public Easy_67( int aNum )
	{
		_binary = new int[32];
		_number = aNum;
	}

	public void convert()
	{
		numToBinary();
		reversedBinaryToDecimal();
	}

	private void numToBinary()
	{
		int num = _number;
		int index = 31;

		while( num > 0 )
		{
			int temp = (int)Math.pow( 2, index );
			if( num >= temp )
			{
				num -= temp;
				_binary[index] = 1;
			}

			index--;
		}
	}

	private void reversedBinaryToDecimal()
	{
		int index = 0;
		long num = 0;

		while( index < 32 )
		{
			if( _binary[index] == 1 )	
			{
				num += (long)Math.pow( 2, 31 - index );
			}
			index++;
		}
		
		System.out.println( Long.toString( num ) );
	}

	public static void main( String[] args )
	{
		Scanner scanner = new Scanner( System.in );
		System.out.print( "Please enter an int: " );
		int num = scanner.nextInt();

		Easy_67 e67 = new Easy_67(num);
		e67.convert();
	}
}