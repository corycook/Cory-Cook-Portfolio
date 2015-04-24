using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cORM
{
    public class DataModel
    {
    }

    public class DataModel<TSource> : DataModel where TSource : DataModel
    {

    }
}
