/*
Created by: Thomas Hewton-Waters
reddit.com/r/dailyprogrammer

Easy #64
The divisors of a number are those numbers that divide it evenly; 
for example, the divisors of 60 are 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, and 60. 
The sum of the divisors of 60 is 168, and the number of divisors of 60 is 12.
The totatives of a number are those numbers less than the given number and coprime to it; 
two numbers are coprime if they have no common factors other than 1. 
The number of totatives of a given number is called its totient. 
For example, the totatives of 30 are 1, 7, 11, 13, 17, 19, 23, and 29, 
and the totient of 30 is 8.
Your task is to write a small library of five functions that compute 
the divisors of a number, the sum and number of its divisors, 
the totatives of a number, and its totient.
*/

import java.util.*;

public class Easy_64
{
	private int number;
	private ArrayList<Integer> divisors;
	private ArrayList<Integer> totatives;

	public Easy_64( int num )
	{
		super();

		number = num;
		divisors = new ArrayList<Integer>();
		totatives = new ArrayList<Integer>();
	}

	public void printSumOfDivisors()
	{
		int sum = 0;

		for( int i = 0; i < divisors.size(); i++ )
		{
			sum += divisors.get( i );
		}

		System.out.println( "Sum of divisors: " + sum );
	}

	public void printNumberOfDivisors()
	{
		System.out.println( "Number of divisors: " + divisors.size() );
	}

	public void printTotient()
	{
		System.out.println( "Totient: " + totatives.size() );
	}

	public void printDivisors()
	{
		getDivisors();

		String str = "";

		for( int i = 0; i < divisors.size(); i++ )
		{
			str += divisors.get( i );

			if( i != divisors.size() - 1 )
			{
				str += ", ";
			}
		}

		System.out.println( "Divisors: " + str );
	}

	private void getDivisors()
	{
		/* 1 is always a divisor */
		divisors.add( 1 );

		for( int i = 2; i <= number / 2; i++ )
		{
			if( number % i == 0 )
			{
				divisors.add( i );
			}
		}

		/* A number is always a divisor of itself */
		divisors.add( number );
	}

	private void printTotatives()
	{
		getTotatives();

		String str = "";

		for( int i = 0; i < totatives.size(); i++ )
		{
			str += totatives.get( i );

			if( i != totatives.size() - 1 )
			{
				str += ", ";
			}
		}

		System.out.println( "Totatives: " + str );
	}

	private void getTotatives()
	{
		for( int possibleTotative = 1; possibleTotative < number; possibleTotative++ )
		{
			ArrayList<Integer> totativeDivs = new ArrayList<Integer>();

			/* 1 is always a divisor */
			totativeDivs.add( 1 );

			for( int j = 2; j <= possibleTotative / 2; j++ )
			{
				if( possibleTotative % j == 0 )
				{
					totativeDivs.add( j );
				}
			}

			/* The possible totative is a divisor of itself */
			totativeDivs.add( possibleTotative );

			if( isTotative( totativeDivs ) == true )
			{
				totatives.add( possibleTotative );
			}
		}
	}

	private boolean isTotative( ArrayList<Integer> totativeDivs )
	{
		for( int i = 1; i < totativeDivs.size(); i++ )
		{
			for( int j = 1; j < divisors.size(); j++ )
			{
				if( totativeDivs.get( i ) == divisors.get( j ) )
				{
					return false;
				}
			}
		}

		return true;
	}

	public static void main( String[] args )
	{
		Scanner scanner = new Scanner( System.in );

		System.out.println( "Please enter a number." );
		String numberString = scanner.nextLine();

		Easy_64 e64 = new Easy_64( Integer.parseInt( numberString ) );
		e64.printDivisors();
		e64.printSumOfDivisors();
		e64.printNumberOfDivisors();
		e64.printTotatives();
		e64.printTotient();

		return;
	}
}

