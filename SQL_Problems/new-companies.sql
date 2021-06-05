-- https://www.hackerrank.com/challenges/the-company/problem
-- For every company query its code, founder, number of lead managers, number of
-- senior managers, number of managers, and number of employees

SELECT E.COMPANY_CODE, C.FOUNDER, COUNT(DISTINCT LEAD_MANAGER_CODE), COUNT(DISTINCT SENIOR_MANAGER_CODE), COUNT(DISTINCT MANAGER_CODE), COUNT(DISTINCT EMPLOYEE_CODE) FROM EMPLOYEE E
JOIN COMPANY C USING(COMPANY_CODE)
GROUP BY E.COMPANY_CODE, C.FOUNDER;

-- Output:
C1 Angela 1 2 5 13 
C10 Earl 1 1 2 3 
C100 Aaron 1 2 4 10 
C11 Robert 1 1 1 1 
C12 Amy 1 2 6 14 
C13 Pamela 1 2 5 14 
C14 Maria 1 1 3 5 
..