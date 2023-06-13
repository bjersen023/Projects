using System;
using System.Data.OleDb;

internal class leDbConnection
{
    public static implicit operator leDbConnection(OleDbConnection v)
    {
        throw new NotImplementedException();
    }
}