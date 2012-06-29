/*
Created by: Thomas Hewton-Waters
reddit.com/r/dailyprogrammer

Hello, coders! An important part of programrng 
is being able to apply your programs, so your 
challenge for today is to create a calculator 
application that has use in your life. It rght 
be an interest calculator, or it rght be 
something that you can use in the classroom. 
For example, if you were in physics class, you 
rght want to make a F = M * A calc.
EXTRA CREDIT: make the calculator have multiple 
functions! Not only should it be able to 
calculate F = M * A, but also A = F/M, and M = F/A!

Calculator: Loan calculator
*/

import java.util.Scanner;

public class Easy_2
{
	private double _principal;
	private double _interest_rate;
	private int _length_in_months;

	private double _monthly_payment;
	private double _interest_per_payment;
	private double _loan_cost;
	private double _interst_paid;

	public Easy_2(double p, double r, int mlen)
	{
		_principal = p;
		_interest_rate = r / 100;
		_length_in_months = mlen;

		monthlyPayment();
		interestPerPayment();
		loanCost();
		interestPaid();
	}

	private void monthlyPayment()
	{
		_monthly_payment = (_principal * (_interest_rate / 12)) / (1 - Math.pow(((1 + _interest_rate / 12)), -1 * _length_in_months));
	}

	private void interestPerPayment()
	{
		_interest_per_payment = _principal * _interest_rate / 12;
	}

	private void loanCost()
	{
		_loan_cost = _monthly_payment * _length_in_months;
	} 

	private void interestPaid()
	{
		_interst_paid = _loan_cost - _principal;
	}

	public String toString()
	{
		String str = "" + "\n\nPrincipal:\t\t" + String.format("%.2f", _principal) + "\n";
		str += "Interest rate:\t" + String.format("%.2f", _interest_rate) + "\n";
		str += "Length (in months):\t" + String.format("%d", _length_in_months) + "\n";
		str += "Monthly payment:\t" + String.format("%.2f", _monthly_payment) + "\n";
		str += "Interest per payment:\t" + String.format("%.2f", _interest_per_payment) + "\n";
		str += "Loan cost:\t\t" + String.format("%.2f", _loan_cost) + "\n";
		str += "Interest paid:\t\t" + String.format("%.2f", _interst_paid) + "\n";

		return str;
	}

	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);

		System.out.println("This app will calculate loan interest.");

		System.out.print("Principal: ");
		double p = scanner.nextDouble();

		System.out.print("Interest rate: ");
		double r = scanner.nextDouble();

		System.out.print("Length of loan (in months): ");
		int mlen = scanner.nextInt();

		Easy_2 lc = new Easy_2(p, r, mlen);
		System.out.println(lc.toString());
	}
}
