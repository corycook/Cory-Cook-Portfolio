SELECT a.name tablename, b.name columnname, b.is_nullable, b.is_identity, b.system_type_id 
FROM sys.all_objects a LEFT JOIN sys.all_columns b 
ON a.object_id = b.object_id 
WHERE a.[type] = 'U' 
AND a.schema_id = 1 
ORDER BY tablename