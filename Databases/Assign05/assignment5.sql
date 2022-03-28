# Name: Harry Chieng
# Z-ID: z1811457
# Section 03

# 1. Show all of the tables in the database.

SHOW TABLES;

# 2. Show all of the columns and other information about all of tables in the databases.

DESCRIBE BabyName;

# 3. Show all of the years (once only) where your first name appears. If your name doesn’t appear, use
Laura if you are female and Luke if you are male.



# 4. Show all of the names from your birth year. (again show each name only once).

SELECT DISTINCT NAME, YEAR FROM BabyName WHERE YEAR = '1994';

# 5. What is the most popular male and female names from your birth year?

SELECT DISTINCT NAME, YEAR FROM BabyName WHERE YEAR = '1994' HAVING COUNT(*)>10000;

# 6. Show all the information about names similar to your name (or the one you used above) in
alphabetic order of the name, and within that of the count, and then of the year.



# 7. How many rows are in the table?

SELECT COUNT(*) FROM BabyName;

# 8. How many names are there in the year 1960?

SELECT SUM(COUNT), YEAR FROM BabyName WHERE YEAR = '1960';

# 9. How many names are there for each sex from the year of your father’s birth? If you don’t know what
year your father was born, use 1927.

SELECT SUM(COUNT), GENDER, YEAR FROM BabyName WHERE YEAR = '1962' AND GENDER = 'M';

SELECT SUM(COUNT), GENDER, YEAR FROM BabyName WHERE YEAR = '1962' AND GENDER = 'F';

# 10. List how many different names there are for each place.


