/*
Created by: Thomas Hewton-Waters
reddit.com/r/dailyprogrammer

create a program that will ask the users name, age, 
and reddit username. have it tell them the information 
back, in the format:
your name is (blank), you are (blank) years old, and your username is (blank)
for extra credit, have the program log this information 
in a file to be accessed later.
*/

import java.util.Scanner;

class Easy_1
{
	String name;
	String age;
	String username;

	public Easy_1( String n, String a, String u )
	{
		this.name = n;
		this.age = a;
		this.username = u;
	}

	public String toString()
	{
		return "Your name is " + name + ", you are " + age + " years old, and your username is " + username + ".";
	}

	public static void main( String[] args )
	{
		System.out.println( "Please enter your name: " );
		Scanner scanner = new Scanner( System.in );

		String name = scanner.nextLine();

		System.out.println( "Please enter your age: " );
		String age = scanner.nextLine();

		System.out.println( "Please enter your reddit username: " );
		String username = scanner.nextLine();

		Easy_1 e1 = new Easy_1( name, age, username );
		System.out.println( e1.toString() );
	}
}