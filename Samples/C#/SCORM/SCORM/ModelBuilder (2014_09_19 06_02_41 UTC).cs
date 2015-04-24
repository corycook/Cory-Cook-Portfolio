
using System;
using System.Linq;
using System.Data;
using System.Reflection.Emit;
using System.Data.SqlClient;
using System.Reflection;
using System.Collections;
using System.Collections.Generic;

namespace SCORM
{
    public static class DataModelBuilder
    {

        public static void BuildModelBuilder(string connectionString)
        {
            SqlConnection connection = new SqlConnection(connectionString);
            SqlCommand command = connection.CreateCommand();
            command.CommandText = "SELECT a.name tablename, b.name columnname, b.is_nullable, b.is_identity, b.system_type_id FROM sys.all_objects a LEFT JOIN sys.all_columns b ON a.object_id = b.object_id WHERE a.[type] = 'U' AND a.schema_id = 1 ORDER BY tablename";
            using (SqlDataAdapter adapter = new SqlDataAdapter(command))
            {
                var set = new DataSet();
                var tableset = new List<TableMap>();
                adapter.Fill(set);
                var tables = from DataRow i in set.Tables[0].Rows select new ColumnMapping(i);
                
            }
        }
    }

    public class ColumnMapping
    {
        public ColumnMapping(DataRow values)
        {
            foreach (var i in GetType().GetProperties())
            {
                i.SetValue(this, values[i.Name], null);
            }
        }

        public string tablename { get; set; }
        public string columnname { get; set; }
        public bool is_nullable { get; set; }
        public bool is_identity { get; set; }
        public int system_type_id { get; set; }
    }

    public class TableMap
    {
        public string Name { get; set; }
        public IList<CellMap> Cells { get; set; }
    }

    public class CellMap
    {
        public string Name { get; set; }
        public Type Type { get; set; }
        public bool Nullable { get; set; }
        public bool Identity { get; set; }

        public static Type Resolve(int typeId)
        {
            switch (typeId)
            {
                case 40:
                case 41:
                case 42:
                case 58:
                case 61:
                    return typeof(DateTime);
                case 56:
                    return typeof(int);
                case 59:
                    return typeof(double);
                case 62:
                    return typeof(float);
                case 104:
                    return typeof(bool);
                case 106:
                    return typeof(decimal);
                case 167:
                case 175:
                case 231:
                case 239:
                    return typeof(string);
                default:
                    return typeof(object);
            }
        }
    }
}
