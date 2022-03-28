# Programmer: Harry Chieng
# Z-ID: z1811457
# Section: 3

# 1. drop/delete all of the tables/views you will be creating below

DROP TABLE Owner, Pet;

# 2. create a table owner with an owner id, a first name, and a last name. Owner id should be an auto-increment primary key.

CREATE TABLE Owner 
(OwnerID int auto_increment PRIMARY KEY, 
FirstName CHAR(20), 
LastName CHAR(20));

# 3. put at least 5 records in this table

INSERT INTO Owner (OwnerID, FirstName, LastName) VALUES 
(09, 'Alex', 'Johnson'),                                  
(10, 'John', 'Skywalker'),                                      
(21, 'Joe', 'Smith'),                                         
(02, 'Joseph', 'Name'),                                       
(59, 'What', 'The');  

# 4. do a select * on this table to show all the records

SELECT * FROM Owner;

# 5. create a table called pet with a pet id (auto-increment primary key), pet name, pet dob (as character), and ownerid (which is a foreign key into the owner table

CREATE TABLE Pet (PetID int auto_increment PRIMARY KEY, PetName CHAR(20), PetDOB CHAR(11), OwnerID int); 

# 6. put at least 5 records in this table, with at least two pets owned by the same owner

INSERT INTO Pet (PetID, PetName, PetDOB, OwnerID) VALUES 
(520, 'Bronco', '06/09/69', 09), 
(151, 'Mallort', '09/06/96', 09), 
(195, 'Jimbo', '06/06/06', 14), 
(512, 'BUckaroo', '09/09/09', 12), 
(156, 'Davey', '12/21/12', 02);

# 7. do a select * on this table to show all the records

SELECT * FROM Pet;

# 8. add a column to the pet table for type of pet (for example: dog, cat, or fish)

ALTER TABLE Pet ADD COLUMN PetType CHAR(20) AFTER OwnerID;

# 9. update several rows to add the pet type



# 10. change the pet dob column to a date type (from character)



# 11. do a select * on this table to show all the records

SELECT * FROM Pet;

# 12. define a view that will list each owner with their pet, just the names (first and last of owner) and the pet name



# 13. do a select * on this view to show all the records.

SELECT * FROM Pet, Owner;
