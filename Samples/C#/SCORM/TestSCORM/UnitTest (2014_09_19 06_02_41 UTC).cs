using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace TestSCORM
{
    [TestClass]
    public class UnitTest
    {
        [TestMethod]
        public void TestDatabase()
        {
            const string _connectionString = "Data Source=(LocalDB)\\v11.0;AttachDbFilename=\"C:\\Users\\Cory\\Documents\\Visual Studio 2013\\Projects\\SCORM\\TestSCORM\\TestDatabase.mdf\";Integrated Security=True;Connect Timeout=30";
            SCORM.DataModelBuilder.BuildModelBuilder(_connectionString);
        }
    }
}
