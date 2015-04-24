using System.Data.SqlClient;
using System.Reflection;
using System.Reflection.Emit;

namespace cORM
{
    public static class ModelBuilder
    {
        public static Assembly BuildModel(string name, string namespaceName, string connectionString, string path = "./")
        {
            var assemblyConstructor = AssemblyBuilder.DefineDynamicAssembly(new AssemblyName(name), AssemblyBuilderAccess.RunAndSave);
            var fileName = name + ".dll";
            var moduleConstructor = assemblyConstructor.DefineDynamicModule(name, fileName, true);

            var connection = SqlClientFactory.Instance.CreateConnection();
            connection.ConnectionString = connectionString;
            connection.StateChange += connection_StateChange;
            return Assembly.LoadFile(path + fileName);
        }

        static void connection_StateChange(object sender, System.Data.StateChangeEventArgs e)
        {
            if (e.CurrentState != System.Data.ConnectionState.Open) return;
            using (SqlCommand command = ((SqlConnection)sender).CreateCommand())
            {
            }
        }
    }
}
