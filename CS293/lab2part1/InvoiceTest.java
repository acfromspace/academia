package lab2part1;

import lab2part1.Invoice;

public class InvoiceTest
{
	public static void main(String[] args)
	{
		Invoice invoice1, invoice2;
		
		invoice1 = new Invoice();
		invoice2 = new Invoice("B", "Shield", 1, 10.00);
		
		System.out.printf ("Invoice1: Item-%s, Amount Due: $%.2f\n",invoice1.getPartDescription(),invoice1.getInvoiceAmount());
		System.out.printf ("Invoice2: Item-%s,Amount Due: $%.2f\n", invoice2.getPartDescription(),invoice2.getInvoiceAmount());
	}
}