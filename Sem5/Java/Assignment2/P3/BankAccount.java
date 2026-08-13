class BankAccount {
	String name;
	int accountNumber;
	char accountType;
	double balance;
		
	BankAccount() {
		accountNumber = (int)(Math.random()*100000);
	}

	double checkBalance() {
		return balance;
	}

	void withdraw(double amount) {
		if(accountType == 'c')
			balance -= amount;
		else if(accountType == 's' && (balance - 1000) >= amount)
			balance -= amount;
		else
			System.out.println("Insufficient Balance!");
	}

	void deposit(double amount) {
		balance += amount;
	}
}