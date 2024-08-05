SELECT 
    HG.SUM_SCORE as SCORE,
    HE.EMP_NO,
    HE.EMP_NAME,
    HE.POSITION,
    HE.EMAIL
FROM 
   HR_EMPLOYEES AS HE
JOIN 
    (select sum(SCORE) as SUM_SCORE ,EMP_NO  
     from HR_GRADE
     group by EMP_NO
    ) 
     AS HG
ON 
    HG.EMP_NO = HE.EMP_NO
ORDER BY 
    HG.SUM_SCORE DESC
LIMIT 1;