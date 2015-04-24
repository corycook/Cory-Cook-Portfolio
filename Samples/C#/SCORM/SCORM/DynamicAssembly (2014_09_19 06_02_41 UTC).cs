using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;

namespace SCORM
{
    public static class DynamicAssembly
    {
        public static string assemblyName = "DataModelBuilder";
        private static string fileName { get { return assemblyName + ".dll"; } }
        private static readonly AssemblyBuilder _assembly = AppDomain.CurrentDomain.DefineDynamicAssembly(new System.Reflection.AssemblyName("DataModelBuilder"), AssemblyBuilderAccess.RunAndSave);
        private static readonly ModuleBuilder _model = _assembly.DefineDynamicModule(assemblyName, fileName);

        public static TypeBuilder CreateType(string name)
        {
            return _model.DefineType(name, TypeAttributes.Class);
        }

        public static TypeBuilder CreateType(string name, Type parent)
        {
            return _model.DefineType(name, TypeAttributes.Class, parent);
        }

        public static TypeBuilder AddProperty(this TypeBuilder typebuilder, string name)
        {
            return typebuilder.
        }
    }
}
