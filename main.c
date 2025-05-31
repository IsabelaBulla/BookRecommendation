#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Define maximum number of books the user can enter
#define MAX_BOOKS 100

int main(void)
{

	// Variables to receive information about the books:
	char bookTitles[MAX_BOOKS][50];
	char genres[MAX_BOOKS];
	int pageCounts[MAX_BOOKS];
	char moods[MAX_BOOKS];

	// Number of books inserted by the user:
	int bookCount = 0; // Start with 0 books

	// Variables to receive user's reading preferences:
	char genrePref;
	char moodPref;
	int minPage, maxPage;
	int numDays;

	// Application title
	printf("**********************************************\n");
	printf("*                                            *\n");
	printf("*  Welcome to our Book Recommendations!      *\n");
	printf("*  Please enter a book to get started.       *\n");
	printf("*                                            *\n");
	printf("**********************************************\n\n");


	// Flag variable to stop adding books loop:
	int addBook = 1; // Assume user wants to add a book

	while (addBook && bookCount < MAX_BOOKS) {

		printf("\nBOOK-%d...\n", bookCount + 1);

		// Validate book title
		int invalidTitle = 1; // Assume user will enter an invalid title
		while (invalidTitle) {
			printf("Title: ");
			scanf(" %[^\n]", bookTitles[bookCount]);

			if (strlen(bookTitles[bookCount]) > 0) {
				invalidTitle = 0;
			}
			else {
				printf("Invalid input! Title cannot be empty.\n");
			}
		}

		// Validate book genre
		int invalidGenre = 1; // Assume user will enter an invalid genre
		do {
			printf("Genre ([M]ystery, [S]ci-fi, [R]omance): ");
			scanf(" %c", &genres[bookCount]);

			if (genres[bookCount] == 'M' || genres[bookCount] == 'S' || genres[bookCount] == 'R' ||
				genres[bookCount] == 'm' || genres[bookCount] == 's' || genres[bookCount] == 'r') {
				invalidGenre = 0;
			}
			else {
				printf("Invalid input! Please enter M, S, or R.\n");
			}

		} while (invalidGenre);

		// Validate page count
		do {
			printf("Page count: ");
			if (scanf("%d", &pageCounts[bookCount]) != 1 || pageCounts[bookCount] <= 0) {
				printf("Invalid input! Please enter a positive number.\n");
				while (getchar() != '\n'); // Clear input buffer
			}
		} while (pageCounts[bookCount] <= 0);

		// Validate Mood
		int invalidMood = 1; // Assume user will enter an invalid mood
		for (; invalidMood;) {
			printf("Mood ([C]alm, [T]hrilling, [E]ducational): ");
			scanf(" %c", &moods[bookCount]);

			if (moods[bookCount] == 'C' || moods[bookCount] == 'T' || moods[bookCount] == 'E' ||
				moods[bookCount] == 'c' || moods[bookCount] == 't' || moods[bookCount] == 'e') {

				invalidMood = 0;
			}
			else {
				printf("Invalid input! Please enter C, T, or E.\n");
			}
		}

		// Increase book count
		bookCount++;

		// Yes-> keep looping | No-> quit loop
		printf("\nDo you want to add another book? (1 = Yes, 0 = No): ");
		scanf("%d", &addBook);

	}

	// Display all books

	printf("\nHere are the books you've entered:\n\n");

	for (int i = 0; i < bookCount; i++) {
		printf("Book %d:\n", i + 1);
		printf("  Title: %s\n", bookTitles[i]);

		printf("  Genre: ");
		switch (genres[i]) {
		case 'M': case 'm':
			printf("Mystery\n");
			break;
		case 'S': case 's':
			printf("Sci-Fi\n");
			break;
		case 'R': case 'r':
			printf("Romance\n");
			break;
		default:
			printf("Unknown\n");
		}

		printf("  Pages: %d\n", pageCounts[i]);

		printf("  Mood: ");
		switch (moods[i]) {
		case 'C': case 'c':
			printf("Calm\n");
			break;
		case 'T': case 't':
			printf("Thrilling\n");
			break;
		case 'E': case 'e':
			printf("Educational\n");
			break;
		default:
			printf("Unknown\n");
		}

		printf("\n");
	}

	// Receive user input for reading preferences
	printf("Please enter your reading preferences: \n");
	
	// Validate book genre preference
	int invalidGenrePref = 1; // Assume input will be invalid!
	while (invalidGenrePref) {
		printf("Preferred genre ([M]ystery, [S]ci-fi, [R]omance): ");
		scanf(" %c", &genrePref);

		if (genrePref == 'M' || genrePref == 'S' || genrePref == 'R' ||
			genrePref == 'm' || genrePref == 's' || genrePref == 'r') {
			invalidGenrePref = 0; // Input is valid, exit loop
		}
		else {
			printf("Invalid input! Please enter M, S, or R.\n");
		}
	}

	// Validate mood preference
	int invalidMoodPref = 1; // Assume input will be invalid!
	while (invalidMoodPref) {
		printf("Preferred reading mood ([C]alm, [T]hrilling, [E]ducational): ");
		scanf(" %c", &moodPref);

		if (moodPref == 'C' || moodPref == 'T' || moodPref == 'E' ||
			moodPref == 'c' || moodPref == 't' || moodPref == 'e') {
			invalidMoodPref = 0; // Input is valid, exit loop
		}
		else {
			printf("Invalid input! Please enter C, T, or E.\n");
		}
	}

	// Validate min page count preference
	int invalidMinPage = 1; // Assume input will be invalid!
	while (invalidMinPage) {
		printf("Enter preferred minimum page count: ");
		if (scanf("%d", &minPage) != 1 || minPage <= 0) {
			printf("Invalid input! Please enter a positive number.\n");
			while (getchar() != '\n'); // Clear input buffer
		}
		else {
			invalidMinPage = 0;
		}
	}

	// Validate max page count preference
	int invalidMaxPage = 1; // Assume input will be invalid!
	while (invalidMaxPage) {
		printf("Enter preferred maximum page count: ");
		if (scanf("%d", &maxPage) != 1 || maxPage < minPage) {
			printf("Invalid input! Maximum must be greater than minimum.\n");
			while (getchar() != '\n'); // Clear input buffer
		}
		else {
			invalidMaxPage = 0;
		}
	}

	// Validate reading days
	int invalidNumDays = 1; // Assume input will be invalid!
	while (invalidNumDays) {
		printf("How many days would you like to finish the book in? ");
		if (scanf("%d", &numDays) != 1 || numDays <= 0) {
			printf("Invalid input! Please enter a positive number.\n");
			while (getchar() != '\n'); // Clear input buffer
		}
		else {
			invalidNumDays = 0;
		}
	}

	printf("\n");

	// Display books that align with these preferences
	int foundBooks = 0; // Flag to check if any books match

	printf("\nBooks that match your preferences:\n\n");

	for (int i = 0; i < bookCount; i++) {
		if ((genres[i] == genrePref) &&
			(moods[i] == moodPref) &&
			(pageCounts[i] >= minPage && pageCounts[i] <= maxPage)) {

			// Display book information
			printf("Book %d:\n", i + 1);
			printf("  Title: %s\n", bookTitles[i]);

			printf("  Genre: ");
			switch (genres[i]) {
			case 'M': case 'm':
				printf("Mystery\n");
				break;
			case 'S': case 's':
				printf("Sci-Fi\n");
				break;
			case 'R': case 'r':
				printf("Romance\n");
				break;
			default:
				printf("Unknown\n");
			}

			printf("  Pages: %d\n", pageCounts[i]);

			// Convert mood letter to full word
			printf("  Mood: ");
			switch (moods[i]) {
			case 'C': case 'c':
				printf("Calm\n");
				break;
			case 'T': case 't':
				printf("Thrilling\n");
				break;
			case 'E': case 'e':
				printf("Educational\n");
				break;
			default:
				printf("Unknown\n");
			}

			// Calculate reading pace per day
			int pagesPerDay = pageCounts[i] / numDays;
			printf("  Estimated Reading Time: %d days (about %d pages per day)\n\n", numDays, pagesPerDay);

			foundBooks = 1; // Set flag to indicate books were found
		}
	}

	// Display appropriate final message
	if (foundBooks) {
		printf("Have a great time reading!\n");
	}
	else {
		printf("Sorry, no books match your preferences.\n");
	}

	return 0;
}