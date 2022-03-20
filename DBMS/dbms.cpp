Joins in SQL:
A SQL Join statement is used to combine data or rows from two or more tables based on a common field between them. 
Different types of Joins are:
INNER JOIN
LEFT JOIN
RIGHT JOIN
FULL JOIN

Normal Join:
	2 tables people(name,state) and states(abbr,full)
	For the above 2 tables state and abbr represents the same.
	*** select * from people join states;
	-	Above query returns the cartesian product of both the tables
	-   Cartesian product is where every row of the 1st table is mapped with every other row of 2nd table
	- 	Can also be done as select * from people,states

Inner Join (Asks for records that overlap):
	2 tables people(name,state) and states(abbr,full)
	For the above 2 tables state and abbr represents the same.
	In the below query only those rows are returned which have the same value for the common attribute.
	***	select * from people join states on people.state=states.abbr;
	-	For the above query the tuples returned which have the same value for the common attribute.
		The unmatched tuples in both the tables are ignored.
	
Outer Joins:
	Left Outer Join:
		2 tables people(name,state) and states(abbr,full)
		For the above 2 tables state and abbr represents the same.
	*** select * from people left join states on people.state=states.abbr		
	-	For the above query the result would include the matching sets of rows from each table similar to inner join	
		Along with this the result would also include the unmatched rows in the left table, For such unmatched rows 
		null values are filled for columns of the right table.	
		
	Right Outer Join:
		2 tables people(name,state) and states(abbr,full)
		For the above 2 tables state and abbr represents the same.
	*** select * from people right join states on people.state=states.abbr
	-	For the above query the result would include the matching sets of rows from each table similar to inner join	
		Along with this the result would also include the unmatched rows in the right table, For such unmatched rows 
		null values are filled for columns of the left table.		
		
	Full Outer Join:
		2 tables people(name,state) and states(abbr,full)
		For the above 2 tables state and abbr represents the same.
	*** select * from people full outer join states on people.state=states.abbr				
	-	For the above query the result would include the matching sets of rows from each table similar to inner join	
		Along with this the result would also include the unmatched rows from the left and right table and those unmatched 
		rows from both the tables are taken and unavailable fiels are filled with null.	
				
Natural Join:
	2 tables people(name,state) and states(state,full)
	*** select * from people natural join states
	-	Natural join takes in the common columns names from the 2 tables and tries to match only those tuples in both the tables
		and gives the result for the matched rows of the columns.
	- 	The common column is repeated only once.
	- 	Natural Join joins two tables based on same attribute name and datatypes. 
	-	The resulting table will contain all the attributes of both the table but keep only one copy of each common column.
	
NATURAL JOIN	
1.	Natural Join joins two tables based on same attribute name and datatypes.	
2.	In Natural Join, The resulting table will contain all the attributes of both the tables 
	but keep only one copy of each common column.

INNER JOIN
1.	Inner Join joins two table on the basis of the column which is explicitly specified in the ON clause.
2.	In Inner Join, The resulting table will contain all the attribute of both the tables including duplicate columns also.
	
		
HACK:USE DOTS(.) WHILE USING JOINS(INNER JOIN AND OUTER JOIN)








