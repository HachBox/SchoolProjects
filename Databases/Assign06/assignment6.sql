# Programmer: Harry Chieng
# Z-ID: z1811457
# Section: 3

# 1 List all owner names last, first and the name and type of their boat and in alphabetic order of last name

SELECT DISTINCT Owner.LastName, Owner.FirstName, MarinaSlip.BoatType 
FROM Owner, MarinaSlip 
WHERE Owner.OwnerNum = MarinaSlip.OwnerNum;

# 2) List all of the owners who have more than one boat, and how many boats they own.

SELECT DISTINCT LastName, FirstName, COUNT(*) AS 'Total Boats'
FROM Owner INNER JOIN MarinaSlip
   ON Owner.OwnerNum = MarinaSlip.OwnerNum
GROUP BY Owner.OwnerNum
HAVING COUNT(*) > 1;	

# 3) For each service request, list the Description of the request as well as the Owner last name.

SELECT Owner.LastName, ServiceRequest.Description 
FROM Owner, MarinaSlip, ServiceRequest 
WHERE Owner.OwnerNum = MarinaSlip.OwnerNum 
	AND MarinaSlip.SlipID = ServiceRequest.SlipID;

# 4) For each service category list the Category Description and how many service requests there are for each category.

SELECT ServiceCategory.CategoryDescription, 
       (SELECT COUNT(*) 
	FROM ServiceRequest
       	WHERE ServiceCategory.CategoryNum = ServiceRequest.CategoryNum) 
FROM ServiceCategory;

# 5) List all of the owners (name, city, and state) and the Name of the marina where they keep their boat, in alphabetic order of city and within city of last name.

SELECT DISTINCT Owner.LastName, Owner.FirstName, Owner.City, Owner.State, Marina.Name 
FROM Owner, Marina, MarinaSlip 
WHERE Owner.OwnerNum = MarinaSlip.OwnerNum 
	AND MarinaSlip.MarinaNum = Marina.Marinanum;

# 6) What is the total rental fee amount for each Marina in the database?

SELECT SUM(MarinaSlip.RentalFee) 
FROM MarinaSlip;

# 7)For each service request list the estimated hours, spent hours and the difference. Just list the ServiceId and the hours information. All the columns should be renamed.

SELECT ServiceID'Service ID',
	EstHours'Estimated Hours', 
	SpentHours'Hours Spent', 
	EstHours-ServiceRequest.SpentHours 'Difference' 
FROM ServiceRequest;

# 8)List the last name of the owners (and their boats name) who own a boat that is 30 feet long or shorter.

SELECT Distinct Owner.LastName, MarinaSlip.BoatName 
FROM Owner, MarinaSlip 
WHERE MarinaSlip.Length > '30' 
	AND Owner.OwnerNum = MarinaSlip.OwnerNum;

# 9) For each boat, list the name and next service date

SELECT DISTINCT MarinaSlip.BoatName, ServiceRequest.NextServiceDate 
FROM MarinaSlip, ServiceRequest 
WHERE MarinaSlip.SlipID = ServiceRequest.SlipID;

# 10) List each boat name, the owners last name, the slip number and Marina name in alphabetic order of boat name within the alphabetic order of the marina name.

SELECT DISTINCT Owner.LastName, MarinaSlip.SlipID, Marina.Name 
FROM Owner, Marina, MarinaSlip, ServiceRequest 
WHERE Owner.OwnerNum = MarinaSlip.OwnerNum 
	AND MarinaSlip.MarinaNum = Marina.MarinaNum;
