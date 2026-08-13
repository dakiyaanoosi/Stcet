import java.util.Scanner;
class BankAccountMain {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		BankAccount p1 = new BankAccount();
		System.out.print("Account Holder Name: ");
		p1.name = sc.nextLine();
		System.out.print("Account Type [s/c]: ");
		p1.accountType = sc.nextLine().charAt(0);
		if(p1.accountType == 's') {
			p1.deposit(1000);
			System.out.println("Minimum deposit of Rs.1000 done successfully");
		}

		System.out.println("\n|| Account Details ||");
		System.out.printf("Name: %s\nAccount Number: %d\nAccount Type: %c\nBalance: %f\n\n", p1.name, p1.accountNumber, p1.accountType, p1.balance);

		double amt;
		while(true) {
			System.out.print("1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\nEnter your choice [1/2/3/4]: ");
			int ch = sc.nextInt();

			switch(ch) {
				case 1: System.out.println("\nBalance: "+p1.checkBalance()\n);
					break;
				case 2: System.out.print("Enter the amount: ");
					amt = sc.nextDouble();
					p1.deposit(amt);
					break;
				case 3: System.out.print("Enter the amount: ");
					amt = sc.nextDouble();
					p1.withdraw(amt);
					break;
				case 4: return;
				default: System.out.println("Invalid Choice!");
			}
		}
	}
}
