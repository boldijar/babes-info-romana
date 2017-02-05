USE [OnlineLottery]

--	QUERY 01:	All clients from United Kingdom
--	Contains:	1x WHERE;
SELECT First_Name, Second_Name
FROM Clients
WHERE Country='United Kingdom'

--	Query 02:	All countries that have clients who participated
--	Contains:	1x DISTINCT
SELECT DISTINCT Country
FROM CLIENTS

--	Query 03:	All cities that have clients who participated
--	Contains:	1x DISTINCT
SELECT DISTINCT City
FROM Clients

--	Query 04:	All clients from Romania that have more than one entry
--	Contains:	1x WHERE, 1x JOIN, 1x GROUP BY, 1x HAVING
SELECT Clients.First_Name, Clients.Second_Name, COUNT(Entries.ID) AS EntriesCount
FROM Entries
INNER JOIN Clients
ON Entries.ClientID=Clients.ID
WHERE Country='Romania'
GROUP BY Clients.First_Name, Clients.Second_Name
HAVING COUNT(Entries.ID)>1;

--	Query 05:	All clients from Turkey that have more than one phone number
--	Contains:	1x WHERE, 1x JOIN, 1x GROUP BY, 1x HAVING
SELECT Clients.First_Name, Clients.Second_Name, COUNT(PhoneNumbers.ID) AS PhoneNumbersCount
FROM PhoneNumbers
INNER JOIN Clients
ON PhoneNumbers.ClientID=Clients.ID
WHERE Country='Turkey'
GROUP BY Clients.First_Name, Clients.Second_Name
HAVING COUNT(PhoneNumbers.ID)>1;

--	Query 06:	All clients sorted by name
--	Contains:	1x ORDER BY
SELECT First_Name, Second_Name FROM Clients
ORDER BY Second_Name, First_Name

--	Query 07:	Number of different cities from each country
--	Contains:	1x GROUP BY, 1x ORDER BY
SELECT DISTINCT Clients.Country, COUNT(Clients.City) AS CityCount
FROM Clients
GROUP BY Clients.Country
ORDER BY CityCount DESC

--	Query 08:	Number of clients from each city
--	Contains:	1x GROUP BY, 1x ORDER BY
SELECT Clients.City, COUNT(Clients.ID) AS ClientsCount
FROM Clients
GROUP BY Clients.City
ORDER BY ClientsCount DESC

--	Query 09:	Number of phones of each client
--	Contains:	1x INNER JOIN, 1x GROUP BY
SELECT Clients.First_Name, Clients.Second_Name, COUNT(PhoneNumbers.ID) AS PhoneNumbersCount
FROM PhoneNumbers
INNER JOIN Clients
ON PhoneNumbers.ClientID=Clients.ID
GROUP BY Clients.First_Name, Clients.Second_Name

--	Query 10:	Number of entries of each client
--	Contains:	1x INNER JOIN, 1x GROUP BY, 1x ORDER BY
SELECT Clients.First_Name, Clients.Second_Name, COUNT(Entries.ID) AS EntriesCount
FROM Entries
INNER JOIN Clients
ON Entries.ClientID=Clients.ID
GROUP BY Clients.First_Name, Clients.Second_Name
ORDER BY EntriesCount DESC