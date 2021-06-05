SELECT B1.N, B1.P, B2.N FROM BST B1
LEFT JOIN BST B2 ON B1.N = B2.P

SELECT N, P, N IN (
	SELECT DISTINCT P FROM BST)
	FROM BST

	
----- ~ OKAY ~ -----
SELECT N, CASE
    WHEN HAS_PRT = 1 AND HAS_CHD = 1 THEN 'Inner'
    WHEN HAS_PRT = 1 AND HAS_CHD = 0 THEN 'Leaf'
    WHEN HAS_PRT = 0 THEN 'Root'
    END AS NodeType
FROM
(SELECT N, P IS NOT NULL AS HAS_PRT, N IN (
    SELECT DISTINCT P FROM BST) IS NOT NULL AS HAS_CHD
    FROM BST) AS T
ORDER BY N

-- 1 Leaf 
-- 2 Inner 
-- 3 Leaf 
-- 4 Inner 
-- 5 Leaf 
-- 6 Inner 
-- 7 Leaf 
-- 8 Leaf 
-- 9 Inner 
-- 10 Leaf 
-- 11 Inner 
-- 12 Leaf 
-- 13 Inner 
-- 14 Leaf 
-- 15 Root 