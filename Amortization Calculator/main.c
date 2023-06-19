#include <stdio.h>
#include <math.h>
// Calculate the value of each installment: pv = Loan amount, i = interest rate, n = Number of installments 
float installment_price(float pv, float i, float n) {
    // Calculate and return the value of each installment using the loan amount, interest rate, and number of installments
    return (pv * i) / (1 - pow(1 / (1 + i), n));
}


// Calculate the total amount based on the number of installments
float total_price(float pv, float i, float n) {
    // Calculate the value of each installment using the installment_price function, and then multiply it by the number of installments to get the total amount
    return installment_price(pv, i, n) * n;
}

// Calculate the interest amount for each installment using the Sum of the Digits (SAC) method
float interest_sac(float pv, float i, float n) {
    // Calculate the total interest amount using the formula: (pv * (n + 1) * i) / (2 * n)
    return (pv * (n + 1) * i) / (2 * n);
}

// Calculate the value of each installment using the Sum of the Digits (SAC) method
float installment_sac(float pv, float i, float n) {
    // Calculate the amortization value, which is the loan amount divided by the number of installments
    float amortization = pv / n;
    // Calculate the interest amount for each installment using the SAC method
    float interest = interest_sac(pv, i, n);
    // Calculate and return the value of each installment by adding the amortization and interest amounts
    return amortization + interest;
}


/// Calculate the total amount based on the number of installments
float total_sac(float pv, float i, float n) {
    // Calculate the sum of the digits from 1 to n
    float sum_of_digits = (n * (n + 1)) / 2;
    // Calculate the interest amount for each installment using the SAC method
    float interest = (pv * i) / sum_of_digits;
    // Calculate the total amount by adding the loan amount and the interest amount
    return pv + (interest * n);
}

void calculatePrice(float pv, float i, float n) {
    printf("\n=== Price System ===\n");

    // Calculate the installment value and total amount using the price system
    float installment = installment_price(pv, i, n);
    float total = total_price(pv, i, n);

    // Print the calculated installment and total amount
    printf("Installment:    R$ %.2f\n", roundf(installment * 100) / 100);
    printf("Total:          R$ %.2f\n", roundf(total * 100) / 100);

    printf("\n=== Amortization Table ===\n");
    printf("Month\tOutstanding Balance\tAmortization\tInterest\t\tPayment\n");

    // Initialize variables for tracking total amortization, total interest, and total payment
    float outstanding_balance = pv;
    float total_amortization = 0;
    float total_interest = 0;
    float total_payment = 0;

    // Generate the amortization table for each month
    for (int month = 1; month <= n; month++) {
        // Calculate the interest amount for the current month
        float interest = outstanding_balance * i;
        // Calculate the amortization amount for the current month
        float amortization = installment - interest;
        // Update the outstanding balance by subtracting the amortization amount
        outstanding_balance -= amortization;

        // Print the details for the current month in the amortization table
        printf("%d\tR$ %.2f\tR$ %.2f\tR$ %.2f\tR$ %.2f\n", month, outstanding_balance, amortization, interest, installment);

        // Update the total amortization, total interest, and total payment
        total_amortization += amortization;
        total_interest += interest;
        total_payment += installment;
    }

    // Print the totals in the amortization table
    printf("Totals:\t\tR$ %.2f\tR$ %.2f\tR$ %.2f\tR$ %.2f\n", outstanding_balance, total_amortization, total_interest, total_payment);
}

void calculateSAC(float pv, float i, float n) {
    printf("\n=== SAC System ===\n");

    // Calculate the total amount using the SAC system
    float total = total_sac(pv, i, n);
    // Calculate the amortization amount for each month
    float amortization = pv / n;
    // Initialize the outstanding balance, total amortization, total interest, and total payment variables
    float outstanding_balance = pv;
    float total_amortization = 0;
    float total_interest = 0;
    float total_payment = 0;

    printf("=== Amortization Table ===\n");
    printf("Month\tPayment\t\tAmortization\tInterest\tOutstanding Balance\n");

    // Generate the amortization table for each month
    for (int month = 1; month <= n; month++) {
        // Calculate the interest amount for the current month
        float interest = outstanding_balance * (i / ((n * (n + 1)) / 2));
        // Calculate the total payment for the current month by adding the amortization and interest amounts
        float payment = amortization + interest;
        // Update the outstanding balance by subtracting the amortization amount
        outstanding_balance -= amortization;

        // Print the details for the current month in the amortization table
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", month, payment, amortization, interest, outstanding_balance);

        // Update the total amortization, total interest, and total payment
        total_amortization += amortization;
        total_interest += interest;
        total_payment += payment;
    }

    // Print the totals in the amortization table
    printf("Totals:\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", total_payment, total_amortization, total_interest, outstanding_balance);
}


int main() {
    int opcao;
    int escolha_calculo;
    float pv, i, n;

    do {
        // Prompt the user to enter the loan details
        printf("Loan amount (R$): ");
        scanf("%f", &pv);

        printf("Interest rate (%%): ");
        scanf("%f", &i);
        i /= 100;

        printf("Number of installments (months/years): ");
        scanf("%f", &n);

        do {
            // Prompt the user to choose the calculation method
            printf("\nChoose the calculation method:\n");
            printf("1 - Price System\n");
            printf("2 - SAC System\n");
            printf("0 - Exit\n");
            printf("Option: ");
            scanf("%d", &escolha_calculo);

            switch (escolha_calculo) {
                case 1:
                    calculatePrice(pv, i, n); // Call the function to calculate using the Price System
                    break;
                case 2:
                    calculateSAC(pv, i, n); // Call the function to calculate using the SAC System
                    break;
                case 0:
                    printf("Exiting the program.\n");
                    return 0;
                default:
                    printf("Invalid option. Please try again.\n");
                    break;
            }

            // Prompt the user to choose an option after the calculation
            printf("\nChoose an option:\n");
            printf("1 - Calculate again with the same values\n");
            printf("2 - Restart the program\n");
            printf("0 - Exit\n");
            printf("Option: ");
            scanf("%d", &opcao);
        } while (opcao == 1);

        if (opcao == 2) {
            printf("Restarting the program.\n");
        } else if (opcao == 0) {
            printf("Exiting the program.\n");
            return 0;
        } else {
            printf("Invalid option. Exiting the program.\n");
            return 0;
        }
    } while (opcao == 2);

    return 0;
}