using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using cORM;

namespace TestcORM
{
    [TestClass]
    public class ModelBuilderTests
    {
        [TestMethod]
        public void TestModelBuilder()
        {
            var assembly = ModelBuilder.BuildModel("TestData", "TestcORM.Models", "Data Source=(LocalDB)\\v11.0;AttachDbFilename=\"C:\\Users\\Cory\\documents\\visual studio 2013\\Projects\\cORM\\cORM\\TestDb.mdf\";Integrated Security=True");
            Assert.IsNotNull(assembly);
        }
    }
}
