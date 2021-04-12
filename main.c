#define PY_SSIZE_T_CLEAN
#include <Python.h>
//#include <python3.8/Python.h>
//#include <python2.7/Python.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

  //sert a initier l'API
    Py_Initialize();

  //sert a choisir le bon chemin de dossiers
  //PyObject *sys = PyImport_ImportModule("sys");
  //PyObject *path = PyObject_GetAttrString(sys, "path");
  //PyList_Append(path, PyString_FromString("."));

  //pour pointer le du dossier actuel chemin
  char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }

  //ajoute un chemin au projet
  PyObject *sys_path = PySys_GetObject("path");
  PyList_Append(sys_path, PyString_FromString(cwd));

  //déclarations
  PyObject *pval;
  char *cString = "Cyberpersons";
  pval = PyString_FromString(cString);

  PyObject *pName;
  PyObject *pModule;
  PyObject *pValue;
  PyObject *pFunc;

  //appel du bon module dans la bonne fonction
  /*
  pName = PyString_FromString("affichage3D.py");
  if (pName == NULL) {
   printf("ERROR importing module (pName)\n");
   exit(-1);
   }
  pModule = PyImport_Import(pName);
  */
  //se résume a ça
  pModule = PyImport_ImportModule("affichage3D");PyErr_Print();

  //insertion des arguments
  PyObject *pythonArgument;
  pythonArgument = PyTuple_New(1);
  pValue = PyString_FromString("argv[3]");

  if(pValue==NULL){
    return 1;
  }
  PyTuple_SetItem(pythonArgument, 0, pValue);

  //appel de la fonction
  // argv[2] is the function name defined in pModule
  // pFunc is the reference to the function
  if (pModule == NULL) {
   printf("ERROR importing module\n");
   exit(-1);
   }
  pFunc = PyObject_GetAttrString(pModule, "printData");
  pValue = PyObject_CallObject(pFunc, pythonArgument);
  if (pValue != NULL) {
    printf("Value returuend from the function %s", PyString_AsString(pValue));
  } else {
    PyErr_Print();
  }
  return 0;
}

/*
//copy in case of disaster
int main(int argc, char *argv[])
{

  //sert a initier l'API
    Py_Initialize();

  //sert a choisir le bon chemin de dossiers
  //PyObject *sys = PyImport_ImportModule("sys");
  //PyObject *path = PyObject_GetAttrString(sys, "path");
  //PyList_Append(path, PyString_FromString("."));

  //pour pointer le du dossier actuel chemin
  char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }

  //ajoute un chemin au projet
  PyObject *sys_path = PySys_GetObject("path");
  PyList_Append(sys_path, PyString_FromString(cwd));


  PyObject *pval;
  char *cString = "Cyberpersons";
  pval = PyString_FromString(cString);

  PyObject *pName;
  PyObject *pModule;
  PyObject *pValue;
  PyObject *pFunc;

  //appel du bon module dans la bonne fonction
  //se résume a ça
  pModule = PyImport_ImportModule("affichage3D");PyErr_Print();

  //insertion des arguments
  PyObject *pythonArgument;
  pythonArgument = PyTuple_New(1);
  pValue = PyString_FromString("argv[3]");

  if(pValue==NULL){
    return 1;
  }
  PyTuple_SetItem(pythonArgument, 0, pValue);

  //appel de la fonction
  // argv[2] is the function name defined in pModule
  // pFunc is the reference to the function
  if (pModule == NULL) {
   printf("ERROR importing module\n");
   exit(-1);
   }
  pFunc = PyObject_GetAttrString(pModule, "printData");
  pValue = PyObject_CallObject(pFunc, pythonArgument);
  if (pValue != NULL) {
    printf("Value returuend from the function %s", PyString_AsString(pValue));
  } else {
    PyErr_Print();
  }
  return 0;
}
*/