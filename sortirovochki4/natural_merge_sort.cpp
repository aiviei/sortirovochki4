#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

template <typename T> void natural_merge_sort(const char* file_name) {
	std::ifstream fin(file_name);
	int n;
	if (!(fin >> n)) {
		fin.close();
	}
	else {
		FILE* main_file = fopen(file_name, "r+");
		FILE* sub_file_f1 = fopen("sub_file_1.txt", "w+");
		FILE* sub_file_f2 = fopen("sub_file_2.txt", "w+");

		FILE* sub_file_g1;
		FILE* sub_file_g2;

		int count_el_main = 0;
		int count_el_sub1 = 0;
		int count_el_sub2 = 0;

		T number = 0;
		int counter = 1;

		if (main_file != NULL) {
			while (feof(main_file) == false) {
				fscanf(main_file, "%f ", &number);
				count_el_main++;
			}
		}
		else {
			std::cout << "File is corrupted!" << std::endl;
		}

		fclose(main_file);

		main_file = fopen(file_name, "r");
		sub_file_f1 = fopen("sub_file_1.txt", "w+");
		sub_file_f2 = fopen("sub_file_2.txt", "w+");

		int turn = 1;
		number = 0;

		while (!feof(main_file)) {
			if (turn == 1) {
				for (int i = 0; i < counter and !feof(main_file); i++) {
					fscanf(main_file, "%f ", &number);
					fprintf(sub_file_f1, "%f ", number);
					count_el_sub1++;
				}
				turn *= -1;
			}
			else {
				for (int j = 0; j < counter and !feof(main_file); j++) {
					fscanf(main_file, "%f ", &number);
					fprintf(sub_file_f2, "%f ", number);
					count_el_sub2++;
				}
				turn *= -1;
			}
		}

		fclose(main_file);
		fclose(sub_file_f1);
		fclose(sub_file_f2);


		turn = 1;

		T number_1;
		T number_2;


		while (counter < count_el_main and count_el_main > 1) {

			if (turn == 1) {
				sub_file_f1 = fopen("sub_file_1.txt", "r");
				sub_file_f2 = fopen("sub_file_2.txt", "r");
				sub_file_g1 = fopen("sub_file_g1.txt", "w");
				sub_file_g2 = fopen("sub_file_g2.txt", "w");
				turn = -1;

				if (!feof(sub_file_f1)) {
					fscanf(sub_file_f1, "%f", &number_1);
				}
				if (!feof(sub_file_f2)) {
					fscanf(sub_file_f2, "%f", &number_2);
				}

				int turn_2 = 1;
				while (!feof(sub_file_f1) and !feof(sub_file_f2)) {
					if (turn_2 == 1) {
						int i = 0;
						int j = 0;
						while (i < counter and j < counter and !feof(sub_file_f1) and !feof(sub_file_f2)) {
							if (number_1 < number_2) {
								fprintf(sub_file_g1, "%f ", number_1);
								fscanf(sub_file_f1, "%f", &number_1);
								i++;
							}
							else {
								fprintf(sub_file_g1, "%f ", number_2);
								fscanf(sub_file_f2, "%f", &number_2);
								j++;
							}
						}

						while (i < counter and !feof(sub_file_f1)) {
							fprintf(sub_file_g1, "%f ", number_1);
							fscanf(sub_file_f1, "%f", &number_1);
							i++;
						}

						while (j < counter and !feof(sub_file_f2)) {
							fprintf(sub_file_g1, "%f ", number_2);
							fscanf(sub_file_f2, "%f", &number_2);
							j++;
						}

						turn_2 = -1;
					}

					else if (turn_2 == -1) {
						int i = 0;
						int j = 0;
						while (i < counter and j < counter and !feof(sub_file_f1) and !feof(sub_file_f2)) {
							if (number_1 < number_2) {
								fprintf(sub_file_g2, "%f ", number_1);
								fscanf(sub_file_f1, "%f", &number_1);
								i++;
							}
							else {
								fprintf(sub_file_g2, "%f ", number_2);
								fscanf(sub_file_f2, "%f", &number_2);
								j++;
							}
						}

						while (i < counter and !feof(sub_file_f1)) {
							fprintf(sub_file_g2, "%f ", number_1);
							fscanf(sub_file_f1, "%f", &number_1);
							i++;
						}

						while (j < counter and !feof(sub_file_f2)) {
							fprintf(sub_file_g2, "%f ", number_2);
							fscanf(sub_file_f2, "%f", &number_2);
							j++;
						}

						turn_2 = 1;
					}
				}

				if (turn_2 == 1) {
					if (!feof(sub_file_f1)) {
						while (!feof(sub_file_f1)) {
							fprintf(sub_file_g1, "%f ", number_1);
							fscanf(sub_file_f1, "%f", &number_1);
						}
					}
					else {
						while (!feof(sub_file_f2)) {
							fprintf(sub_file_g1, "%f ", number_2);
							fscanf(sub_file_f2, "%f", &number_2);
						}
					}
				}

				else if (turn_2 == -1) {
					if (!feof(sub_file_f1)) {
						while (!feof(sub_file_f1)) {
							fprintf(sub_file_g2, "%f ", number_1);
							fscanf(sub_file_f1, "%f", &number_1);
						}
					}
					else {
						while (!feof(sub_file_f2)) {
							fprintf(sub_file_g2, "%f ", number_2);
							fscanf(sub_file_f2, "%f", &number_2);
						}
					}
				}

				counter *= 2;


				fclose(sub_file_f1);
				fclose(sub_file_f2);
				fclose(sub_file_g1);
				fclose(sub_file_g2);
			}

			else if (turn == -1) {
				sub_file_f1 = fopen("sub_file_1.txt", "w");
				sub_file_f2 = fopen("sub_file_2.txt", "w");
				sub_file_g1 = fopen("sub_file_g1.txt", "r");
				sub_file_g2 = fopen("sub_file_g2.txt", "r");

				turn = 1;

				if (!feof(sub_file_g1)) {
					fscanf(sub_file_g1, "%f", &number_1);
				}
				if (!feof(sub_file_g2)) {
					fscanf(sub_file_g2, "%f", &number_2);
				}

				int turn_2 = 1;

				while (!feof(sub_file_g1) and !feof(sub_file_g2)) {
					if (turn_2 == 1) {
						int i = 0;
						int j = 0;
						while (i < counter and j < counter and !feof(sub_file_g1) and !feof(sub_file_g2)) {
							if (number_1 < number_2) {
								fprintf(sub_file_f1, "%f ", number_1);
								fscanf(sub_file_g1, "%f", &number_1);
								i++;
							}
							else {
								fprintf(sub_file_f1, "%f ", number_2);
								fscanf(sub_file_g2, "%f", &number_2);
								j++;
							}
						}

						while (i < counter and !feof(sub_file_g1)) {
							fprintf(sub_file_f1, "%f ", number_1);
							fscanf(sub_file_g1, "%f", &number_1);
							i++;
						}

						while (j < counter and !feof(sub_file_g2)) {
							fprintf(sub_file_f1, "%f ", number_2);
							fscanf(sub_file_g2, "%f", &number_2);
							j++;
						}

						turn_2 = -1;
					}
					else if (turn_2 == -1) {
						int i = 0;
						int j = 0;
						while (i < counter and j < counter and !feof(sub_file_g1) and !feof(sub_file_g2)) {
							if (number_1 < number_2) {
								fprintf(sub_file_f2, "%f ", number_1);
								fscanf(sub_file_g1, "%f", &number_1);
								i++;
							}
							else {
								fprintf(sub_file_f2, "%f ", number_2);
								fscanf(sub_file_g2, "%f", &number_2);
								j++;
							}
						}


						while (i < counter and !feof(sub_file_g1)) {
							fprintf(sub_file_f2, "%f ", number_1);
							fscanf(sub_file_g1, "%f", &number_1);
							i++;
						}

						while (j < counter and !feof(sub_file_g2)) {
							fprintf(sub_file_f2, "%f ", number_2);
							fscanf(sub_file_g2, "%f", &number_2);
							j++;
						}

						turn_2 = 1;
					}
				}

				if (turn_2 == 1) {
					if (!feof(sub_file_g1)) {
						while (!feof(sub_file_g1)) {
							fprintf(sub_file_f1, "%f ", number_1);
							fscanf(sub_file_g1, "%f", &number_1);
						}
					}
					else {
						while (!feof(sub_file_g2)) {
							fprintf(sub_file_f1, "%f ", number_2);
							fscanf(sub_file_g2, "%f", &number_2);
						}
					}
				}
				else if (turn_2 == -1) {
					if (!feof(sub_file_g1)) {
						while (!feof(sub_file_g1)) {
							fprintf(sub_file_f2, "%f ", number_1);
							fscanf(sub_file_g1, "%f", &number_1);
						}
					}
					else {
						while (!feof(sub_file_g2)) {
							fprintf(sub_file_f2, "%f ", number_2);
							fscanf(sub_file_g2, "%f", &number_2);
						}
					}
				}

				counter *= 2;

				fclose(sub_file_f1);
				fclose(sub_file_f2);
				fclose(sub_file_g1);
				fclose(sub_file_g2);
			}

		}

		if (turn == 1) {
			main_file = fopen(file_name, "w+");
			sub_file_f1 = fopen("sub_file_1.txt", "r");

			while (!feof(sub_file_f1)) {
				fscanf(sub_file_f1, "%f ", &number_1);
				fprintf(main_file, "%f ", number_1);
			}

			fclose(main_file);
			fclose(sub_file_f1);
		}
		else {
			main_file = fopen(file_name, "w+");
			sub_file_g1 = fopen("sub_file_g1.txt", "r");

			while (!feof(sub_file_g1)) {
				fscanf(sub_file_g1, "%f ", &number_1);
				fprintf(main_file, "%f ", number_1);
			}

			fclose(main_file);
			fclose(sub_file_g1);
		}
	}
}