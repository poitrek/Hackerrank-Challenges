------ OK ------
SELECT CEIL(AVG(SALARY - REPLACE(SALARY, '0', ''))) FROM EMPLOYEES
-- REPLACE(SALARY, '0', '') - remove all zeros from the number
-- CEIL() - round to the next integer (ceiling)