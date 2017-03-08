<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.01 Transitional//EN' "http://www.w3.org/TR/html4/loose.dtd">
<%@LANGUAGE="JAVASCRIPT" CODEPAGE="1252"%>
<html lang="es" >

<!-- #INCLUDE File="../includes/Adojavas.asp" -->
<!-- #INCLUDE File="../includes/FuncionesRecordset.asp" -->
<!-- #INCLUDE File="../includes/FuncionesFechas.asp" -->
<!-- #INCLUDE File="../includes/FuncionesString.asp" -->
<!-- #INCLUDE File="../includes/FuncionesMsg.asp" -->
<!-- #INCLUDE File="../includes/FuncionesVentanas.asp" -->
<!-- #INCLUDE File="../includes/PortalRegulacion.asp" -->
<!-- #INCLUDE File="../includes/FuncionesControlUsuarios.asp" -->
<!-- #INCLUDE File="../includes/FuncionesControlUsuarios_Irca.asp" -->
<!-- #INCLUDE File="../includes/IrcaLayaout_03.asp" -->
<!-- #INCLUDE File="../includes/FuncionesDatos.asp" -->
<!-- #INCLUDE File="../includes/FuncionesDatosIrca.asp" -->
<!-- #INCLUDE File="../includes/FuncionesDatosIrca_2.asp" -->
<!-- #INCLUDE File="../includes/Irca.asp" -->

<% Response.Buffer=true %> 






<head>
<title>IRCA</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<meta name="keywords"    content="">
<meta name="description" content="">
<meta name="Author"      content="Telefonica Espana, Copyright 2007" > 

<link href="../estilos/IR_Estilos.css" rel="stylesheet"    type="text/css">
<link href="../estilos/apl.css"        rel="stylesheet"    type="text/css" media="screen, print"/>
<link href="../estilos/favicon.ico"    rel="shortcut icon" type="image/x-icon"/>


<script type="text/JavaScript" src="../Js/FN_Fechas.js"         ></script> 
<script type="text/JavaScript" src="../Js/FN_String.js"         ></script> 
<script type="text/JavaScript" src="../Js/FN_Datos.js"          ></script> 
<script type="text/JavaScript" src="../Js/FN_Datos_2.js"        ></script> 
<script type="text/JavaScript" src="../Js/FN_AppGeneral_Irca.js"></script> 
<script type="text/JavaScript">
<!--
function MM_reloadPage(init) {  //reloads the window if Nav4 resized
  if (init==true) with (navigator) {if ((appName=="Netscape")&&(parseInt(appVersion)==4)) {
    document.MM_pgW=innerWidth; document.MM_pgH=innerHeight; onresize=MM_reloadPage; }}
  else if (innerWidth!=document.MM_pgW || innerHeight!=document.MM_pgH) location.reload();
}
MM_reloadPage(true);
//-->



// ----------------------------------
//
// ---------------------------------- 

var selCListaCom = false;





// ----------------------------------
//
// ---------------------------------- 
function enviarDatos_01()
{
  var sNombre      = new String();
  var sInstructor  = new String();
  var sAnno        = new String();
  var sCod         = new String();
  var sCod2        = new String();
  var sNum         = new String();
  var sFRespuesta  = new String();
  var sFRelevante  = new String();
  var sDApertura   = new String();
  var sResumen     = new String();
  var sResumenItem = new String();
  var sTmp         = new String();
  var sExpTCOM     = new String();
  var cExpTCOM;
  var cResponsable;
  var idx;
  var resultado;


  resultado    = true;
  sNombre      = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NOMBRE.value);
  sInstructor  = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_INSTRUCTOR_NOMBRE.value);
  sAnno        = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_ANNO.value);
  sNum         = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NUM.value);
  sCod         = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_COD.value);
  sFRespuesta  = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXPITEM_FERESPUESTA.value);
  sFRelevante  = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXPITEM_FERELEVANTE.value);
  sResumen     = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_RESUMEN.value);
  sResumenItem = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXPITEM_RESUMEN.value);
  cResponsable =  0 + parseFloat(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").SEL_RESPONSABLE.value);
  sDApertura   = "" + document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_DOC_APERTURA.value;

  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NOMBRE.value            = sNombre;
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_INSTRUCTOR_NOMBRE.value = sInstructor;
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_ANNO.value              = sAnno;
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NUM.value               = sNum;
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_COD.value               = sCod;
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXPITEM_FERESPUESTA.value   = sFRespuesta;
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXPITEM_FERELEVANTE.value   = sFRelevante;
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_RESUMEN.value           = sResumen;
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXPITEM_RESUMEN.value       = sResumenItem;
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_DOC_APERTURA.value      = sDApertura;
  
  if ( FN_ValidarDatosExpIDE(sAnno,sNum,sCod)==false )
     { // -----------------------------------
       // -----------------------------------
	   sTmp  = "";
	   sTmp += "Los datos indicados para generar el Código del Expediente no son correctos.\n";
       sTmp += "Revise el formato de los datos tecleados y compruebe que contienen caráteres válidos.\n";
       alert(sTmp);
       document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_ANNO.focus();
       resultado = false;
     }

  if ( sFRespuesta.length!=0 )
     { if ( FN_ValidarFecha(sFRespuesta)==false)
	      { // --------------------------------
	        // --------------------------------
 	        alert("La fecha de respuesta asociada al documento de Apertura del expediente no es correcta");
    	    document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXPITEM_FERESPUESTA.focus();
  	        resultado= false;
	      }
     }

  if ( FN_ValidarFecha(sFRelevante)==false)
     { // --------------------------------
	   // --------------------------------
 	   alert("La fecha relevante asociada al documento de Apertura del expediente no es correcta");
	   document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXPITEM_FERELEVANTE.focus();
  	   resultado= false;
	 }

  if ( cResponsable==-1 ) 
     { // --------------------------------
	   // --------------------------------
 	   alert("Debe especificar un RESPONSABLE en Regulación para el expediente");
	   document.getElementById("FORM_AD_EXPEDIENTE_ALTA").SEL_RESPONSABLE.focus();
 	   resultado = false;
	 }

  if ( sNombre.length==0 ) 
     { // --------------------------------
	   // --------------------------------
 	   alert("Debe especificar un NOMBRE para el expediente");
	   document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NOMBRE.focus();
 	   resultado = false;
	 }
	  
  if ( sDApertura.length==0 ) 
     { // --------------------------------
	   // --------------------------------
  	   alert("Debe especificar el fichero de apertura de expediente");
 	   document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_DOC_APERTURA.focus();
	   resultado = false;
 	 } 
 
  if ( document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_TIPO[4].checked )
     { // --------------------------------------
       // Expediente de reposicion, DEBE 
	   // haber codigo de expediente relacionado
	   // --------------------------------------
       sAnno = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_R_ANNO.value);
       sNum  = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_R_NUM.value);
       sCod  = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_R_COD.value);
       sCod2 = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_COD.value);
	   if ( FN_ValidarDatosExpIDE(sAnno,sNum,sCod)==false )
		  { // -------------------------
		    // -------------------------
            alert("Los datos para generar el codigo del expediente relacionado NO son correctos");     			   
		    resultado = false;
		  }
	   
	   if ( (sCod2==EXP_TIPO_CMT_AJ) && (sCod==EXP_TIPO_CMT_AJ) )	  
		  {
	        alert("Un expediente de Reposición NO puede recurrir a otro del mismo tipo");     			   
		    resultado = false;
		  }  
	 }


  if ( document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_TIPO[3].checked )  
     { // ----------------------------------------------
       // Expediente sancionador, DEBE 
	   // haber codigo de expediente relacionado
	   // YA NO ES OBLIGATORIO, MODIFICACION_ 02/03/2010
	   // PRIORIDAD: 6
	   // ----------------------------------------------
       sAnno = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_S_ANNO.value);
       sNum  = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_S_NUM.value);
       sCod  = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_S_COD.value);
	   
	   if ( (sAnno.length>0) || (sNum.length>0) )
	      { // ----------------------------------------
		    // Especifica un codigo concreto
			// ----------------------------------------
   	        if ( FN_ValidarDatosExpIDE(sAnno,sNum,sCod)==false )
	           { // -------------------------
		         // -------------------------
                 alert("Los datos para generar el codigo del expediente sancionador NO son correctos");     			   
		         resultado = false;
		       }
		  }
	 }

  if ( document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_TIPO[1].checked )   
     { // --------------------------------------
       // Expediente por comunicacion debe 
	   // haber codigo
	   // --------------------------------------
	   if ( resultado==true )
	      { sTmp = "" + document.getElementById("FORM_AD_EXPEDIENTE_ALTA").COMCMT_COD_01.value;
  	        if ( sTmp.length!=MAX_COD_COMUNICACION_CMT_1 )
			   {
			     resultado = false;
			   }
	   	  }    	   

	   if ( resultado==true )
	      { sTmp = "" + document.getElementById("FORM_AD_EXPEDIENTE_ALTA").COMCMT_COD_02.value;
  	        if ( sTmp.length!=MAX_COD_COMUNICACION_CMT_2 )
			   {
			     resultado = false;
			   }
	   	  }    	   
			   
	   if ( resultado==true )
	      { sTmp = "" + document.getElementById("FORM_AD_EXPEDIENTE_ALTA").COMCMT_COD_03.value;
  	        if ( sTmp.length!=MAX_COD_COMUNICACION_CMT_3 )
			   {
			     resultado = false;
			   }
	   	  }    	   
			   
	   if ( resultado==false )
	      {
		    alert("Los datos indicados en el Código de Comunicación a CMT no son correctos");     			   
		  }
     }
	 
  sTmp = "" + (document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_OP_LISTA_VISIBLE.value);
  if ( ((document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_TIPO[2].checked==true) && (sTmp.length==0)) ||
       ((document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_TIPO[4].checked==true) && (sTmp.length==0)) 
     )
     {
	   alert("No se ha seleccionado el/los operador(es) denunciantes");
	   resultado = false;
	 } 
 
  if ( resultado==true )
     { 
	   if ( document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_OP_BE.checked==true ) 
	      {
  		    document.getElementById("CEnvioFinal_BE").style.visibility = "visible";
		  }
	   document.getElementById("CEnvioFinal").style.visibility = "visible";
	 }
}



// ----------------------------------
//
// ---------------------------------- 

function ctrlChkBE()
{
  if ( document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_OP_BE.checked == true )	   
     {
	   document.getElementById("CEnvioFinal_BE").style.visibility = "visible";
	 }
  else
     {
   	   document.getElementById("CEnvioFinal_BE").style.visibility = "hidden";
	 }
}



// ----------------------------------
//
// ---------------------------------- 

function enviarDatos_02()
{
  document.getElementById("CEnvioFinal").style.visibility = "hidden";
}


// ---------------------------------------------
// Esta  funcion  se ha modificado el 01/10/2014
// Al incorporar los nuevos tipos de expedientes
// no contemplados hasta ahora en IRCA.
// ---------------------------------------------

function enviarDatos_03()
{
  var cAutoID;
  var idx;

  
  idx     = 0  + parseInt(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_COD.selectedIndex);
  cAutoID = 0  + parseInt(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_COD_AUTOID.options[idx].text);
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_COD_AUTOID.value = cAutoID;
	
  document.getElementById("CEnvioFinal").style.visibility = "hidden";
  document.getElementById("CMsg1_Prp").style.visibility   = "visible";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").submit();   
}


// ----------------------------------
//
// ---------------------------------- 

function enviarDatos_04()
{
  if ( document.getElementById("CEnvioFinal_BE").style.visibility == "visible" )	   
     {
  	   document.getElementById("CEnvioFinal_BE").style.visibility = "hidden";
	 }
  else
     {
	   document.getElementById("CEnvioFinal_BE").style.visibility = "visible";
	 }
}





// ----------------------------------
//
// ---------------------------------- 
function refrescar()
{
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_ANNO.value              = "";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_COD.value               = "";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NUM.value               = "";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NOMBRE.value            = "";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_INSTRUCTOR_NOMBRE.value = "";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_DOC_APERTURA.value      = "";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_RESUMEN.value           = "";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").submit();   
}



// ----------------------------------
//
// ---------------------------------- 
function displayCExpIde_RS()
{
  var comID;
  var indTComLista;
  var chkID;  


  iniCamposExp();

  selCListaCom = false;

  setTComSaltar("",0);	   
  
  if ( document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_TIPO[0].checked )  
     {
       document.getElementById("CRIde_011").style.visibility   = "hidden";
	   document.getElementById("CRIde_012").style.visibility   = "hidden";
       document.getElementById("CRIde_013").style.visibility   = "hidden";
	   document.getElementById("CRIde_014").style.visibility   = "hidden";
	   document.getElementById("CRIde_015").style.visibility   = "hidden";
  	   document.getElementById("CRIde_016").style.visibility   = "hidden";
       document.getElementById("CRIde_017").style.visibility   = "hidden";
	   document.getElementById("CSIde_011").style.visibility   = "hidden";
	   document.getElementById("CSIde_012").style.visibility   = "hidden";
       document.getElementById("CSIde_013").style.visibility   = "hidden";
	   document.getElementById("CSIde_014").style.visibility   = "hidden";
	   document.getElementById("CSIde_015").style.visibility   = "hidden";
  	   document.getElementById("CSIde_016").style.visibility   = "hidden";
   	   document.getElementById("CSIde_017").style.visibility   = "hidden";
  	   document.getElementById("CComCMT_Prp").style.visibility = "hidden";
       CComCMT_setCListaCom("hidden");
	   document.getElementById("CTexp_Denuncia_Ope").style.visibility = "hidden";      
	 }

  if ( document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_TIPO[1].checked )  
     {
       document.getElementById("CRIde_011").style.visibility = "hidden";
	   document.getElementById("CRIde_012").style.visibility = "hidden";
       document.getElementById("CRIde_013").style.visibility = "hidden";
	   document.getElementById("CRIde_014").style.visibility = "hidden";
	   document.getElementById("CRIde_015").style.visibility = "hidden";
  	   document.getElementById("CRIde_016").style.visibility = "hidden";
       document.getElementById("CRIde_017").style.visibility = "hidden";
	   document.getElementById("CSIde_011").style.visibility = "hidden";
	   document.getElementById("CSIde_012").style.visibility = "hidden";
       document.getElementById("CSIde_013").style.visibility = "hidden";
	   document.getElementById("CSIde_014").style.visibility = "hidden";
	   document.getElementById("CSIde_015").style.visibility = "hidden";
  	   document.getElementById("CSIde_016").style.visibility = "hidden";
   	   document.getElementById("CSIde_017").style.visibility = "hidden";

       document.getElementById("FORM_AD_EXPEDIENTE_ALTA").T_COMCMT_ID.selectedIndex = 0;
    // ----------------------------------------------
	// Eliminado por la incidencia de PRIORIDAD 10
	// 08/04/2013 
	// Tambien en IR_InterfazExpComunicaciones.asp
    // ----------------------------------------------
    // setTComSaltar("7",0);
  	   document.getElementById("CComCMT_Prp").style.visibility  = "visible";
	   CComCMT_setCListaCom("visible");

	   document.getElementById("FORM_AD_EXPEDIENTE_ALTA").OPE_ID.selectedIndex = 0;	   
  	   document.getElementById("CTexp_Denuncia_Ope").style.visibility = "hidden";
	 }
  
  if ( document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_TIPO[2].checked )  
     {
	   document.getElementById("CRIde_011").style.visibility   = "hidden";
	   document.getElementById("CRIde_012").style.visibility   = "hidden";
       document.getElementById("CRIde_013").style.visibility   = "hidden";
	   document.getElementById("CRIde_014").style.visibility   = "hidden";
	   document.getElementById("CRIde_015").style.visibility   = "hidden";
  	   document.getElementById("CRIde_016").style.visibility   = "hidden";
       document.getElementById("CRIde_017").style.visibility   = "hidden";
	   document.getElementById("CSIde_011").style.visibility   = "hidden";
	   document.getElementById("CSIde_012").style.visibility   = "hidden";
       document.getElementById("CSIde_013").style.visibility   = "hidden";
	   document.getElementById("CSIde_014").style.visibility   = "hidden";
	   document.getElementById("CSIde_015").style.visibility   = "hidden";
  	   document.getElementById("CSIde_016").style.visibility   = "hidden";
   	   document.getElementById("CSIde_017").style.visibility   = "hidden";
  	   document.getElementById("CComCMT_Prp").style.visibility = "hidden";
       CComCMT_setCListaCom("hidden");
	   
	   selDenunciaBorrar();
       
	   // ----------------------------------
	   //	
       // ----------------------------------
			
 	   indTComLista = 0;
	   comID        = 0 + parseFloat(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").COMCMT_COD_05.value );

       if ( comID!=-1 ) 
	      {
   	        while ( 1 )
		          {
			        chkID = 0 + parseFloat(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").T_COMCMT_ID[indTComLista].value); 
			        if ( chkID==comID ) { break;           }
			        else	            { indTComLista++;  }
			      }
		  }
	 
	 //document.getElementById("FORM_AD_EXPEDIENTE_ALTA").T_COMCMT_ID.selectedIndex = 5;
       document.getElementById("FORM_AD_EXPEDIENTE_ALTA").T_COMCMT_ID.selectedIndex = indTComLista;
	   
	   // ----------------------------------------------
	   // Modificado por la incidencia de PRIORIDAD 11
   	   // 06/05/2013 
	   // Tambien en IR_AdminExpedientes_MC.asp
       // ----------------------------------------------
       // setTComSaltar("1-2-3-4-5-6-8-9-10-11-18",5);
	   setTComSaltar("",0);	

	   document.getElementById("FORM_AD_EXPEDIENTE_ALTA").OPE_ID.selectedIndex = 0;
   	   document.getElementById("CTexp_Denuncia_Ope").style.visibility = "visible";
	   selCListaCom = true;
	 }
	 	 
  if ( document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_TIPO[3].checked )  
     {
       document.getElementById("CRIde_011").style.visibility   = "hidden";
	   document.getElementById("CRIde_012").style.visibility   = "hidden";
       document.getElementById("CRIde_013").style.visibility   = "hidden";
	   document.getElementById("CRIde_014").style.visibility   = "hidden";
	   document.getElementById("CRIde_015").style.visibility   = "hidden";
  	   document.getElementById("CRIde_016").style.visibility   = "hidden";
       document.getElementById("CRIde_017").style.visibility   = "hidden";
	   document.getElementById("CSIde_011").style.visibility   = "visible";
	   document.getElementById("CSIde_012").style.visibility   = "visible";
       document.getElementById("CSIde_013").style.visibility   = "visible";
	   document.getElementById("CSIde_014").style.visibility   = "visible";
	   document.getElementById("CSIde_015").style.visibility   = "visible";
  	   document.getElementById("CSIde_016").style.visibility   = "visible";
   	   document.getElementById("CSIde_017").style.visibility   = "visible";
  	   document.getElementById("CComCMT_Prp").style.visibility = "hidden";
       CComCMT_setCListaCom("hidden");
   	   document.getElementById("CTexp_Denuncia_Ope").style.visibility = "hidden";
	 }

  if ( document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_TIPO[4].checked )  
     { 
	   document.getElementById("CRIde_011").style.visibility   = "visible";
	   document.getElementById("CRIde_012").style.visibility   = "visible";
       document.getElementById("CRIde_013").style.visibility   = "visible";
	   document.getElementById("CRIde_014").style.visibility   = "visible";
	   document.getElementById("CRIde_015").style.visibility   = "visible";
  	   document.getElementById("CRIde_016").style.visibility   = "visible";
       document.getElementById("CRIde_017").style.visibility   = "visible";
	   document.getElementById("CSIde_011").style.visibility   = "hidden";
	   document.getElementById("CSIde_012").style.visibility   = "hidden";
       document.getElementById("CSIde_013").style.visibility   = "hidden";
	   document.getElementById("CSIde_014").style.visibility   = "hidden";
	   document.getElementById("CSIde_015").style.visibility   = "hidden";
  	   document.getElementById("CSIde_016").style.visibility   = "hidden";
   	   document.getElementById("CSIde_017").style.visibility   = "hidden";
  	   document.getElementById("CComCMT_Prp").style.visibility = "hidden";
       CComCMT_setCListaCom("hidden");
	   
   	   selDenunciaBorrar();
  	   document.getElementById("FORM_AD_EXPEDIENTE_ALTA").OPE_ID.selectedIndex = 0;
   	   document.getElementById("CTexp_Denuncia_Ope").style.visibility = "visible";
	 }
}



// ----------------------------------
//
// ---------------------------------- 
function clsCodigo()
{
  var cSelec;
  var sSelec;

  cSelec = 0  + document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXPTCOM_ID.selectedIndex;
  sSelec = "" + document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXPTCOM_ID.options[cSelec].text;
  if ( sSelec=="Ninguno" )  
     { 
 	   document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXPTCOM_COD.value="";
	 } 
}



// ----------------------------------
//
// ---------------------------------- 

function iniInterfazComCMT()
{

  selComCMT();
  CComCMT_setCListaCom("hidden");

  // ----------------------------------------
  // Vuelve visible el campo para seleccionar
  // la categoria del expediente
  // ----------------------------------------
  document.getElementById("CCat_Prp").style.visibility = "visible";
}



// ----------------------------------
//
// ---------------------------------- 

function displayHelp_01()
{
  if ( document.getElementById("CHelp_01").style.visibility == "hidden" ) { document.getElementById("CHelp_01").style.visibility = "visible"; }
  else                                                                    { document.getElementById("CHelp_01").style.visibility = "hidden";  }
}	 


// ----------------------------------
//
// ---------------------------------- 

function displayHelp_02()
{
  if ( document.getElementById("CHelp_02").style.visibility == "hidden" ) { document.getElementById("CHelp_02").style.visibility = "visible"; }
  else                                                                    { document.getElementById("CHelp_02").style.visibility = "hidden";  }
}	 


// ----------------------------------
//
// ---------------------------------- 

function displayHelp_03()
{
  if ( document.getElementById("CHelp_03").style.visibility == "hidden" ) { document.getElementById("CHelp_03").style.visibility = "visible"; }
  else                                                                    { document.getElementById("CHelp_03").style.visibility = "hidden";  }
}	 




// ---------------------------------------------
//
// NOTA:
// Esta  funcion  se ha modificado el 01/10/2014
// Al incorporar los nuevos tipos de expedientes
// no contemplados hasta ahora en IRCA.
// ---------------------------------------------

function selCodExpCMT()
{
  var sSelec = new String();
  var sAux   = new String();
  var cAutoID;
  var idx;
  var maxNum;
  var i;
  

  sSelec  = "" + document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_COD.value;
  idx     = 0  + parseInt(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_COD.selectedIndex);
  cAutoID = 0  + parseInt(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_COD_AUTOID.options[idx].text);
  maxNum  = 0  + parseInt(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NUM.maxLength);


  document.getElementById("CTexp_Recurso_OPE").style.visibility = "hidden";
  document.getElementById("CTexp_Sancionador").style.visibility = "hidden";
  
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_TIPO[0].checked = true;
  iniCamposExp();
  
  if ( sSelec==EXP_TIPO_CMT_AJ )
     {
       document.getElementById("CTexp_Recurso_OPE").style.visibility = "visible";
     }
	  
  if ( sSelec==EXP_TIPO_CMT_RO )
     { 
	   document.getElementById("CTexp_Sancionador").style.visibility = "visible";
	 }
 		 
		 
  if ( cAutoID==0 ) 		 
     { // ------------------------------------------------
  	   // Rellena el campo EXP_NUM con 0000 para que no de
	   // error en loschequeos previos al envio de datos 
	   // ------------------------------------------------
	   sAux = "";
	   for( i=0;i<maxNum;i++ ) 
	      {
			sAux += "0";   
		  }
       document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NUM.value            = sAux;
       document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NUM.style.visibility = "hidden";
	   document.getElementById("CHelp_02").style.visibility                        = "visible";
	   document.getElementById("CDExp_10").style.visibility                        = "hidden";
	 }
  else
     {
       document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NUM.value            = "";
       document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_NUM.style.visibility = "visible";
       document.getElementById("CHelp_02").style.visibility                        = "hidden";
  	   document.getElementById("CDExp_10").style.visibility                        = "visible";
	 }
  
  
  
  
  
  displayCExpIde_RS();
}



// ----------------------------------
//
// ---------------------------------- 

function iniCamposExp()
{
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_R_ANNO.value = "";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_R_NUM.value  = "";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_S_ANNO.value = "";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_S_NUM.value  = "";
}



// ----------------------------------
//
// ---------------------------------- 

var hndWExpWizard = null;

function setExpWizard()
{
  var sPagina = new String();
  
  sPagina       = "IR_AdminExpWizard.asp";
  hndWExpWizard = window.open( sPagina         ,
                               "setExpWizard"  ,
	                           "height=220,width=650,left=200,top=200,location=NO,toolbar=NO,status=NO,resizable=NO,alwaysRaised=YES"
		                     );
}

 
 
// ----------------------------------
//
// ---------------------------------- 

function expWizardClose()
{
  if ( hndWExpWizard!=null )
     {
       hndWExpWizard.close();
	 } 
}



// ----------------------------------
//
// ---------------------------------- 

function selDenunciaLista()
{
  var selNombre = new String();
  var selID     = new String();
  var sTmp1     = new String();
  var sTmp2     = new String();
  var sSep1     = new String();
  var sSep2     = new String();
  var idx;
  
  
  idx       =  0 +            document.getElementById("FORM_AD_EXPEDIENTE_ALTA").OPE_ID.selectedIndex;
  selNombre = "" + FN_AllTrim(document.getElementById("FORM_AD_EXPEDIENTE_ALTA").OPE_ID[idx].text);
  selID     = "" +            document.getElementById("FORM_AD_EXPEDIENTE_ALTA").OPE_ID[idx].value;
  
  if ( selNombre.length>0 )
     {
       sTmp1 = "" + document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_OP_LISTA_VISIBLE.value;
       sTmp2 = "" + document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_OP_LISTA_ID.value;
       sSep1 = "";
       sSep2 = "";
  
       if ( (selCListaCom==true) && (selID==45) )
	      { // --------------------------------------
		    // El operador seleccionado es Telefonica
			// --------------------------------------
 	        selComCMT();
	        document.getElementById("CComCMT_Prp").style.visibility = "visible";
		    CComCMT_setCListaCom("visible");
		  }
	   else
		  {
 		    document.getElementById("CComCMT_Prp").style.visibility = "hidden";
 		    CComCMT_setCListaCom("hidden");
		  }
			   
       if ( testIDOpeRepeticion(selID,sTmp2)==false )
          {
            if ( sTmp1.length>0 ) { sSep1 = "\n"; } 
            if ( sTmp2.length>0 ) { sSep2 = "-";  } 
	 
            document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_OP_LISTA_VISIBLE.value = sTmp1 + sSep1 + selNombre;	 
            document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_OP_LISTA_ID.value      = sTmp2 + sSep2 + selID;	 
		  }
     }
}



// ----------------------------------
//
// ---------------------------------- 

function selDenunciaBorrar()
{
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_OP_LISTA_VISIBLE.value = "";
  document.getElementById("FORM_AD_EXPEDIENTE_ALTA").EXP_OP_LISTA_ID.value      = "";
   
  document.getElementById("CRIde_011").style.visibility   = "hidden";
  document.getElementById("CRIde_012").style.visibility   = "hidden";
  document.getElementById("CRIde_013").style.visibility   = "hidden";
  document.getElementById("CRIde_014").style.visibility   = "hidden";
  document.getElementById("CRIde_015").style.visibility   = "hidden";
  document.getElementById("CRIde_016").style.visibility   = "hidden";
  document.getElementById("CRIde_017").style.visibility   = "hidden";
  document.getElementById("CComCMT_Prp").style.visibility = "hidden";
  CComCMT_setCListaCom("hidden");
}





</script>

<noscript>
<p>Esta página necesita ejecutar JavaScript. Utilice un Navegador compatible con JavaScript. Gracias.</p>
<p>This page needs to run JavaScript. Use a browser that supports JavaScript. Thanks.</p>
</noscript>

</head>




<body style="background-color: transparent;"  onLoad="iniInterfazComCMT()"  onUnload="expWizardClose()">
<%

// ----------------------------------
//
// crearFormulario
// REVISADA: 02/03/2010
//
// ---------------------------------- 

function crearFormulario()
{
  var sPagina = new String();
  var sTitulo = new String();
  var sTmp    = new String();
  var posY;  
  var posX; 
 
 
  sTitulo  = "Administraci&oacute;n&nbsp;de&nbsp;expedientes,&nbsp;creaci&oacute;n...";
  sPagina  = "../" + IDE_DIR_ASP + "/" + IDE_PAG_ASP_IRCA_ADMIN_EXP_AS2;
  posY     = 30;
  
  Response.Write('<FORM METHOD="post" ACTION="' + sPagina + '" target="S_Frame" id="FORM_AD_EXPEDIENTE_ALTA" name="FORM_AD_EXPEDIENTE_ALTA"  enctype="multipart/form-data">');

  Response.Write('<div title="' + sTitulo + '" id="CIde_01" align="left" style="position:absolute; width:150px; height:25px; top:5px">');
  Response.Write('<span class="GesDocTexto02">ADMINISTRACI&Oacute;N</span>');
  Response.Write('</div>');

  Response.Write('<div title="' + sTitulo + '" id="CIde_02" class="GesDocSel02" align="center" style="position:absolute; width:360px; height:15px; top:13px; left:240px;">');
  Response.Write('<span>&nbsp;CREACI&Oacute;N&nbsp;DE&nbsp;EXPEDIENTES</span>');
  Response.Write('</div>');

  posY += 30;
  Response.Write('<div title="' + sTitulo + '" id="CIde_03" class="GesDocTexto06" style="position:absolute; left:5px; top:' + posY + 'px;"> ');
  Response.Write('<span>Expediente</span>');
  Response.Write('</div>');
  
  // --------------------------------------
  // Ventanas de ayuda en campos fecha
  // --------------------------------------

  sTitulo = "Fecha&nbsp;relevante";
  sTmp    = "La&nbsp;fecha&nbsp;relevante&nbsp;es&nbsp;la&nbsp;fecha&nbsp;en&nbsp;la&nbsp;que&nbsp;el&nbsp;expediente&nbsp;entra&nbsp;en<br>Telef&oacute;nica."
  sTmp   += "<br>Es&nbsp;un&nbsp;dato&nbsp;obligatorio."
  FN_IRCA_WMsg_01(90,120,"CHelp_01","displayHelp_01()","hidden",sTmp,sTitulo);

  sTitulo = "Fecha&nbsp;respuesta";
  sTmp    = "La&nbsp;fecha&nbsp;de&nbsp;respuesta&nbsp;es&nbsp;la&nbsp;fecha&nbsp;en&nbsp;la&nbsp;que&nbsp;se&nbsp;debe&nbsp;responder<br>a&nbsp;la&nbsp;entrada&nbsp;de&nbsp;un&nbsp;expediente."
  sTmp   += "<br>Es&nbsp;un&nbsp;dato&nbsp;opcional."
  FN_IRCA_WMsg_01(90,120,"CHelp_03","displayHelp_03()","hidden",sTmp,sTitulo);

  // --------------------------------------
  // Ventana de ayuda en campo EXP_NUM
  // --------------------------------------

  sTitulo = "Campo&nbsp;TIPO&nbsp;de&nbsp;Expediente";
  sTmp    = "Para&nbsp;el&nbsp;TIPO&nbsp;de&nbsp;expediente&nbsp;que&nbsp;ha&nbsp;seleccionado<br>";
  sTmp   += "NO&nbsp;es&nbsp;posible&nbsp;indicar&nbsp;&nbsp;en&nbsp;este&nbsp;momento&nbsp;el&nbsp;c&oacute;digo&nbsp;porque&nbsp;se&nbsp;generar&aacute;<br>AUTOM&Aacute;TICAMENTE&nbsp;al&nbsp;crear&nbsp;el&nbsp;expediente."
  FN_IRCA_WMsg_01(90,120,"CHelp_02","displayHelp_02()","hidden",sTmp,sTitulo);

  // -----------------------------------
  // Ventana con aviso de envio de datos
  // -----------------------------------
  
  ventanaMsgEnvio();
  posY -= 10;
  posX  = 70;

  // ----------------------------------
  // Campos para EXPEDIENTE IDE
  // ----------------------------------

  
  FN_DisplayInterfazExpIDE(posY, posX,true,false,"","","");

  // ----------------------------------
  // Campos para Wizard de Creacion
  // ----------------------------------

  displayBotonWizard();
  
  // ----------------------------------
  // Campo Categoria
  // ----------------------------------
  
  posY += 50;
  cmd_Categoria(posY,posX);
     
  // ----------------------------------
  // Campo responsable en Regulacion de
  // este expediente
  // ----------------------------------
  
  posY += 7;
  cmd_Responsable(posY,posX);
    
  // ----------------------------------
  // Campo Nombre del instructor
  // ----------------------------------
  
  posY += 30;  
  cmd_Instructor(posY,posX);
  
  // ----------------------------------
  // Campo Nombre del expediente
  // ----------------------------------
  
  posY += 30; 
  cmd_NExpediente(posY,posX);

  // ----------------------------------
  // Campo resumen
  // ----------------------------------

  posY += 40;
  cmd_Resumen(posY,posX);

  // ----------------------------------
  // Campo documento de apertura
  // ----------------------------------
  
  posY += 60;
  cmd_DocApertura(posY,posX);
  
  // ----------------------------------
  // Campo  resumen  del  documento  de 
  // apertura
  // ----------------------------------

  posY += 35;
  cmd_DocAperturaR(posY,posX);

  // ----------------------------------
  // Campo fecha relevante para el Item
  // de apertura
  // ----------------------------------
  
  posY += 55;
  cmd_FRelevante(posY,posX);
  
  // ----------------------------------
  // Campo fecha de respuesta el Item
  // de apertura
  // ----------------------------------

  posY += 30;
  cmd_FRespuesta(posY,posX);
  
  // ----------------------------------
  // Campo Tipo de expediente
  // ----------------------------------

  posY += 30;
  cmd_TipoExpediente(posY,posX);

  // ----------------------------------
  // Boton enviar
  // ----------------------------------
  
  posY = 520;
  botonEnviar(posY,posX);

  Response.Write('</FORM>');
  
}



// ---------------------------------------
//
// displayBotonWizard
// REVISADA: 02/03/2010
// REVISADA: 01/10/2014
//
// ---------------------------------------

function displayBotonWizard()
{
  var sTitulo = new String();


 //sTitulo = "Asistente&nbsp;para&nbsp;duplicar";	
 //Response.Write('<div title="' + sTitulo + '" id="CExp_Wizard" class="GesDocSel08" align="left" style="position:absolute; cursor:pointer; width:35px; height:50px; left:565px; top:50px">');
 //Response.Write('<img src="../Images/BC/P_ruedas.png" onclick="setExpWizard()" alt="Asistente&nbsp;para&nbsp;duplicar&nbsp;expedientes..."  border="0">');
 //Response.Write('</div>');
  
  sTitulo = "";	
  Response.Write('<div title="' + sTitulo + '" id="CExp_Wizard" class="GesDocSel08" align="left" style="position:absolute; width:35px; height:50px; left:565px; top:50px">');
  Response.Write('</div>');

}



// ---------------------------------------
//
// cmd_Categoria
// REVISADA: 02/03/2010
//
// ---------------------------------------

function cmd_Categoria(posY,posX)
{
  FN_GenerarListaCExpedientes(posY,5,false,false,IDE_EXPEDIENTES_CAT_NOSELEC,"GesDocSel01");
}


// ---------------------------------------
//
// cmd_Responsable
//
// REVISADA: 22/06/2010
//
// ---------------------------------------

function cmd_Responsable(posY,posX)
{
  FN_GenerarListaResponsables(posY,292,0,"GesDocSel01",IDE_EXPEDIENTES_RESP_NOSELEC);
}



// ---------------------------------------
//
// cmd_instructor
//
// REVISADA: 16/03/2010
//
// ---------------------------------------

function cmd_Instructor(posY,posX)
{
  var sTitulo = new String();


  sTitulo = "Persona&nbsp;asociada&nbsp;o&nbsp;responsable&nbsp;de&nbsp;este&nbsp;expediente&nbsp;en&nbsp;CMT...";
  Response.Write('<div  title="' + sTitulo + '" id="CInstructor_01" class="GesDocTexto06" style="position:absolute; left:5px; top:' + posY + 'px;"> ');
  Response.Write('<span>Instructor</span>');
  Response.Write('</div>');
  
  Response.Write('<div   title="' + sTitulo + '" id="CInstructor_02" style="position:absolute; left:70px; top:' + posY + 'px;"> ');
  Response.Write('<input title="' + sTitulo + '" id="EXP_INSTRUCTOR_NOMBRE" name="EXP_INSTRUCTOR_NOMBRE" class="GesDocSel01"   style="width:530px;" maxlength="' + MAX_EXP_INSTRUCTOR_NOMBRE + '" value="">');
  Response.Write('</div>');
}



// ---------------------------------------
//
// cmd_NExpediente
//
// REVISADA: 16/03/2010
//
//
// ---------------------------------------

function cmd_NExpediente(posY,posX)
{
  var sTitulo = new String();
  

  sTitulo = "Nombre&nbsp;de&nbsp;este&nbsp;expediente...";  
  Response.Write('<div title="' + sTitulo + '" id="CNombre_01" class="GesDocTexto06" style="position:absolute; left:5px; top:' + posY + 'px;"> ');
  Response.Write('<span>Nombre</span>');
  Response.Write('</div>');

  posY += -3;
  Response.Write('<div      title="' + sTitulo + '" id="CNombre_02" style="position:absolute; left:70px; top:' + posY + 'px;"> ');
  Response.Write('<textarea title="' + sTitulo + '" class="GesDocSel01" style="resize:none;" id="EXP_NOMBRE" name="EXP_NOMBRE" rows="2" cols="85"></textarea>');
  Response.Write('</div>');
}



// ---------------------------------------
//
// cmd_Resumen
//
// REVISADA: 16/03/2010
//
// ---------------------------------------

function cmd_Resumen(posY,posX)
{
  var sTitulo = new String();
  

  sTitulo = "Resumen&nbsp;del&nbsp;contenido&nbsp;del&nbsp;expediente...";  
  Response.Write('<div title="' + sTitulo + '" id="CDescripcion_01" class="GesDocTexto06" style="position:absolute; width:50px; left:5px; top:' + posY + 'px;"> ');
  Response.Write('<span>Resumen<br>expediente<br>(&nbsp;Opcional&nbsp;)</span>');
  Response.Write('</div>');

  posY += 0;
  Response.Write('<div      title="' + sTitulo + '" id="CDescripcion_02" class="GesDocTexto06" style="position:absolute; width:500px; height:22px; left:70px; top:' + posY + 'px;"> ');
  Response.Write('<textarea title="' + sTitulo + '" class="GesDocSel01" id="EXP_RESUMEN" name="EXP_RESUMEN" style="resize:none;" rows="3" cols="85"></textarea>');
  Response.Write('</div>');
}



// ---------------------------------------
//
// cmd_DocApertura
//
// REVISADA: 16/03/2010
//
// ---------------------------------------

function cmd_DocApertura(posY,posX)
{
  var sTitulo = new String();
  

  sTitulo = "Documento&nbsp;de&nbsp;apertura&nbsp;del&nbsp;expediente...";  
  Response.Write('<div title="' + sTitulo + '" id="CDoc_01" class="GesDocTexto06" style="position:absolute; width:50px; left:5px; top:' + posY + 'px;"> ');
  Response.Write('<span>Documento<br>Apertura</span>');
  Response.Write('</div>');

  Response.Write('<div   title="' + sTitulo + '" id="CDoc_02" style="position:absolute; left:70px; top:' + posY + 'px;">');
  Response.Write('<input title="' + sTitulo + '" class="GesDocSel01" type="File" id="EXP_DOC_APERTURA" name="EXP_DOC_APERTURA" style="width:530px;" >');
  Response.Write('</div>');
}



// ---------------------------------------
//
// cmd_DocAperturaR
//
// REVISADA: 16/03/2010
//
// ---------------------------------------

function cmd_DocAperturaR(posY,posX)
{
  var sTitulo = new String();
  

  sTitulo = "Resumen&nbsp;del&nbsp;documento&nbsp;de&nbsp;apertura...";  
  Response.Write('<div title="' + sTitulo + '" id="CDocResumen_01" class="GesDocTexto06" style="position:absolute; width:50px; left:5px; top:' + posY + 'px;"> ');
  Response.Write('<span>Resumen<br>documento<br>apertura(&nbsp;Opcional&nbsp;)</span>');
  Response.Write('</div>');

  posY += 0
  Response.Write('<div      title="' + sTitulo + '" id="CDocResumen_02" class="GesDocTexto06" style="position:absolute; width:500px; height:22px; left:70px; top:' + posY + 'px;"> ');
  Response.Write('<textarea title="' + sTitulo + '" class="GesDocSel01" id="EXPITEM_RESUMEN" name="EXPITEM_RESUMEN" style="resize:none;" rows="2" cols="85"></textarea>');
  Response.Write('</div>');
}



// ---------------------------------------
//
// cmd_FRelevante
//
// REVISADA: 16/03/2010
//
// ---------------------------------------

function cmd_FRelevante(posY,posX)
{
  var sTitulo = new String();
  

  sTitulo = "Fecha&nbsp;en&nbsp;la&nbsp;que&nbsp;el&nbsp;expediente&nbsp;ENTRA&nbsp;en&nbsp;Telef&oacute;nica...";  
      
  Response.Write('<div title="' + sTitulo + '" id="CFeRelevante_01" class="GesDocTexto06" style="position:absolute; width:50px; left:5px; top:' + posY + 'px;"> ');
  Response.Write('<span>Fecha<br>relevante</span>');
  Response.Write('</div>');

  Response.Write('<div   title="' + sTitulo + '" id="CFeRelevante_02" class="GesDocTexto06" style="position:absolute; left:' + posX + 'px; top:' + posY + 'px;"> ');
  Response.Write('<input title="' + sTitulo + '" class="GesDocSel01" id="EXPITEM_FERELEVANTE" name="EXPITEM_FERELEVANTE" style="width:80px;" maxlength="' + MAX_FECHA + '" value="">');
  Response.Write('</div>');

  Response.Write('<div  title="' + sTitulo + '"  id="CFeRelevante_03" class="texto16" style="position:absolute; left:' + (posX+120) + 'px; top:' + (posY-5) + 'px;"> ');
  Response.Write('<span>obligatorio</span>');
  Response.Write('</div>');

  Response.Write('<div  title="' + sTitulo + '"  id="CFeRelevante_04" class="texto16" style="position:absolute; left:' + (posX+120) + 'px; top:' + (posY+7) + 'px;"> ');
  Response.Write('<span>dd/mm/aaaa</span>');
  Response.Write('</div>');

  Response.Write('<div  title="' + sTitulo + '" id="CFeRelevante_05" align="center" style="position:absolute; cursor:pointer; left:' + (posX+85) +'px; top:' + (posY-10) + 'px" >')
  Response.Write('<img src="../Images/BC/P_BInfo_01.png" alt="Informaci&oacute;n&nbsp;sobre&nbsp;la&nbsp;fecha&nbsp;relevante..." onClick="displayHelp_01()" border="0">')
  Response.Write('</div>')
 
  FN_ExpedienteFRelevanteAyuda();
}



// ---------------------------------------
//
// cmd_FRespuesta
//
// REVISADA: 16/03/2010
//
// ---------------------------------------

function cmd_FRespuesta(posY,posX)
{
  var sTitulo = new String();
  

  sTitulo = "Fecha&nbsp;en&nbsp;la&nbsp;que&nbsp;se&nbsp;DEBE&nbsp;responder&nbsp;a&nbsp;este&nbsp;expediente...";  
      
  Response.Write('<div title="' + sTitulo + '" id="CFeRespuesta_01" class="GesDocTexto06" style="position:absolute; width:50px; left:5px; top:' + posY + 'px;"> ');
  Response.Write('<span>Fecha<br>respuesta</span>');
  Response.Write('</div>');

  Response.Write('<div   title="' + sTitulo + '" id="CFeRespuesta_02" class="GesDocTexto06" style="position:absolute; left:' + posX + 'px; top:' + posY + 'px;"> ');
  Response.Write('<input title="' + sTitulo + '" class="GesDocSel01" id="EXPITEM_FERESPUESTA" name="EXPITEM_FERESPUESTA"  style="width:80px;" maxlength="' + MAX_FECHA + '" value="">');
  Response.Write('</div>');
  
  Response.Write('<div  title="' + sTitulo + '"  id="CFeRespuesta_03" class="texto16" style="position:absolute; left:' + (posX+120) + 'px; top:' + (posY+7) + 'px;"> ');
  Response.Write('<span>dd/mm/aaaa</span>');
  Response.Write('</div>');

  Response.Write('<div  title="' + sTitulo + '" id="CFeRelevante_04" align="center" style="position:absolute; cursor:pointer; left:' + (posX+85) +'px; top:' + (posY-10) + 'px" >')
  Response.Write('<img src="../Images/BC/P_BInfo_01.png" alt="Informaci&oacute;n&nbsp;sobre&nbsp;la&nbsp;fecha&nbsp;relevante..." onClick="displayHelp_03()" border="0">')
  Response.Write('</div>')

  FN_ExpedienteFRespuestaAyuda();
}



// ---------------------------------------
//
// cmd_TipoExpediente
//
// REVISADA: 16/03/2010
//
// ---------------------------------------

function cmd_TipoExpediente(posY,posX)
{
  var sTitulo = new String();

  
  sTitulo = "Tipo&nbsp;de&nbsp;expedientes...";
  Response.Write('<div title="' + sTitulo + '" id="CTexp_Prp" class="GesDocTexto06" style="position:absolute; width:50px; left:5px; top:' + posY + 'px;"> ');
  Response.Write('<span>Tipo<br>Expediente</span>');
  Response.Write('</div>');

  sTitulo = "Expediente&nbsp;normal...";
  Response.Write('<div   title="' + sTitulo + '" id="CTexp_Normal" style="position:absolute; left:' + posX + 'px; top:' + posY + 'px;">');
  Response.Write('<input title="' + sTitulo + '" type="Radio" onclick="displayCExpIde_RS()" id="EXP_TIPO"  name="EXP_TIPO" value="' + EXP_TIPO_NORMAL  + '" checked >');
  Response.Write('<span class="GesDocTexto06">Normal</span>');
  Response.Write('</div>');
  
  posY   += 17;
  sTitulo = "Expediente&nbsp;por&nbsp;Comunicaci&oacute;n&nbsp;de&nbsp;TdE..."; 
  Response.Write('<div   title="' + sTitulo + '" id="CTexp_Comunicacion" style="position:absolute; left:' + posX + 'px; top:' + posY + 'px;">');
  Response.Write('<input title="' + sTitulo + '" type="Radio" onclick="displayCExpIde_RS()" id="EXP_TIPO" name="EXP_TIPO" value="' + EXP_TIPO_COMUNICACION + '">');
  Response.Write('<div   title="' + sTitulo + '" id="CTexp_C01" style="position:absolute; width:350px; height:30px; left:20px; top:5px;">');
  Response.Write('<span class="GesDocTexto06">Por&nbsp;comunicaci&oacute;n&nbsp;de&nbsp;TdE</span>');
  Response.Write('</div>');
  Response.Write('</div>');
  
  FN_DisplayInterfazCom_CMT(posY-90,235,false,"GesDocSel01",2,"",true);
  
  posY   += 17;
  sTitulo = "Denuncia&nbsp;de&nbsp;otro(s)&nbsp;operador(es)...";
  Response.Write('<div   title="' + sTitulo + '" id="CTexp_Denuncia" style="position:absolute; left:' + posX + 'px; top:' + posY + 'px;">');
  Response.Write('<input title="' + sTitulo + '" type="Radio" onclick="displayCExpIde_RS()" id="EXP_TIPO" name="EXP_TIPO" value="' + EXP_TIPO_DENUNCIA + '">');
  Response.Write('<div   title="' + sTitulo + '" id="CTexp_D01" style="position:absolute; width:350px; height:30px; left:20px; top:5px;">');
  Response.Write('<span class="GesDocTexto06">Denuncia<br>de&nbsp;Operador(es)</span>');
  Response.Write('</div>');
  Response.Write('</div>');
  
  Response.Write('<div title="' + sTitulo + '" id="CTexp_Denuncia_Ope" class="GesDocSel08" style="visibility:hidden; position:absolute; width:420px; height:60px;  left:180px; top:' + (posY+50) + 'px;">');  
  FN_GenerarListaOperadores(3,5,false,IDE_OPERADOR_NOSELEC,"GesDocSel01","selDenunciaLista()");
  Response.Write('<div title="' + sTitulo + '" id="CTexp_O01" align="justify" class="GesDocTexto06" style="position:absolute; width:350px; height:30px; left:5px; top:25px;">');
  Response.Write('<span >Si&nbsp;el&nbsp;denunciante&nbsp;no&nbsp;aparece&nbsp;en&nbsp;la<br>lista,&nbsp;seleccione&nbsp;"' + "Otro Operador" + '" </span>');
  Response.Write('</div>');
  Response.Write('<div title="' + sTitulo + '" id="CTexp_O02" align="justify" style="position:absolute; width:200px; height:55px; left:217px; top:2px;">');
  Response.Write('<textarea readonly class="GesDocSel04" id="EXP_OP_LISTA_VISIBLE" name="EXP_OP_LISTA_VISIBLE" rows="4" cols="35"></textarea>');
  Response.Write('</div>');
  Response.Write('<div title="' + sTitulo + '" id="CTexp_O03" align="left" style="position:absolute; visibility:hidden; width:210px; height:45px; left:217px; top:2px;">');
  Response.Write('<input             class="GesDocSel01" id="EXP_OP_LISTA_ID" name="EXP_OP_LISTA_ID" >');
  Response.Write('</div>');
  Response.Write('<div title="' + sTitulo + '" id="CTexp_O04" align="left" style="position:absolute; cursor:pointer; left:182px; top:25px;">');
  Response.Write('<img src="../Images/BC/P_BExit_01.png" onclick="selDenunciaBorrar()" alt="Eliminar&nbsp;operadores..."  border="0">');
  Response.Write('</div>');
  Response.Write('</div>');
  
  posY   += 30;
  sTitulo ="Expediente&nbsp;Sancionador...";
  Response.Write('<div   title="' + sTitulo + '" id="CTexp_Sancionador" style="visibility:hidden; position:absolute; left:' + posX + 'px; top:' + posY + 'px;">');
  Response.Write('<input title="' + sTitulo + '" type="Radio" onclick="displayCExpIde_RS()" id="EXP_TIPO" name="EXP_TIPO" value="' + EXP_TIPO_SANCIONADOR + '">');
  Response.Write('<div   title="' + sTitulo + '" id="CTexp_S01" style="position:absolute; width:350px; height:30px; left:20px; top:5px;">');
  Response.Write('<span class="GesDocTexto06">Sancionador</span>');
  Response.Write('</div>');
  Response.Write('</div>');
  
  FN_DisplayInterfazExpIDE_S(posY+10,180,false,"GesDocSel01","","","");
    
  Response.Write('<div   title="' + sTitulo + '" id="CTexp_Recurso_OPE" style="visibility:hidden; position:absolute; left:' + posX + 'px; top:' + posY + 'px;">');
  Response.Write('<input title="' + sTitulo + '" type="Radio" onclick="displayCExpIde_RS()" id="EXP_TIPO" name="EXP_TIPO" value="' + EXP_TIPO_REPOSICION_OPE + '">');
  Response.Write('<div   title="' + sTitulo + '" id="CTexp_R01" style="position:absolute; width:350px; left:20px; top:5px;">');
  Response.Write('<span class="GesDocTexto06">Recurso<br>Reposici&oacute;n</span>');
  Response.Write('</div>');
  Response.Write('</div>');
  
  FN_DisplayInterfazExpIDE_R(posY+90,180,false,"GesDocSel01","","","");
}



// ---------------------------------------
//
// botonEnviar
// REVISADA: 12/01/2011
// ---------------------------------------

function botonEnviar(posY,posX)
{
  var sTitulo = new String();

  sTitulo = "Crear&nbsp;expediente...";

  Response.Write('<div title="' + sTitulo + '"                   id="CBoton_OK1" style="position:absolute; cursor:pointer; left:70px; top:' + posY + 'px;" >');
  Response.Write('<img src="../Images/BC/IR_BAlta_01.png" onclick="enviarDatos_01()" alt="' + sTitulo + '"  border="0" >');
  Response.Write('</div>');
  
  sTitulo = "Crear&nbsp;una&nbsp;tarea&nbsp;en&nbsp;la&nbsp;Bandeja&nbsp;de&nbsp;entrada&nbsp;del&nbsp;responsable...";
  posY += 50;
  Response.Write('<div   title="' + sTitulo + '"                 id="CBoton_OK2" style="position:absolute; cursor:pointer; left:75px; top:' + posY + 'px;" >');
  Response.Write('<input title="' + sTitulo + '" type="checkbox" id="EXP_OP_BE"  name="EXP_OP_BE" value="SI" onclick="ctrlChkBE()" checked >');
  Response.Write('</div>');
  
  Response.Write('<div   title="' + sTitulo + '"                 id="CBoton_OK3" style="position:absolute; width:100px; left:95px; top:' + posY + 'px;"> ');
  Response.Write('<span class="GesDocTexto06">Crear&nbsp;tarea&nbsp;en&nbsp;la&nbsp;BE<br>del&nbsp;responsable</span>');
  Response.Write('</div>');

}



// ---------------------------------------
//
// ventanas de mensajes de envio
//
// ---------------------------------------

function ventanaMsgEnvio()
{
  var sTexto  = new String();
  var sTitulo = new String();

  // ---------------------------------------
  //
  // ---------------------------------------
  sTitulo  = "Tarea&nbsp;en&nbsp;Bandeja&nbsp;de&nbsp;Entrada";
  sTexto   = "<br>Se&nbsp;ha&nbsp;marcado&nbsp;el&nbsp;check&nbsp;de<br>'crear&nbsp;una&nbsp;tarea&nbsp;en&nbsp;la&nbsp;Bandeja&nbsp;de&nbsp;entrada&nbsp;del&nbsp;responsable";
  sTexto  += "<br>de&nbsp;este&nbsp;expediente'.";
  FN_IRCA_WMsg_01(200,120,"CEnvioFinal_BE","enviarDatos_04()","hidden",sTexto,sTitulo);

  // ---------------------------------------
  //
  // ---------------------------------------
  sTitulo = "Confirmaci&oacute;n&nbsp;de&nbsp;envio&nbsp;de&nbsp;Datos";
  sTexto  = "<br>SE&nbsp;VAN&nbsp;A&nbsp;ENVIAR&nbsp;LOS&nbsp;DATOS<br>";
  sTexto += "&iquest;&nbsp;Realmente&nbsp;desea&nbsp;crear&nbsp;este&nbsp;Expediente&nbsp;?";
  FN_IRCA_WMsg_02(200,120,"CEnvioFinal" ,"enviarDatos_02()","enviarDatos_03()","hidden",sTexto,sTitulo);
  FN_IRCA_WMsg_03(200,120,0,"hidden");
}



// ---------------------------------------
//
//
//    CODIGO PRINCIPAL DE LA PAGINA
//
//
// ---------------------------------------

Response.Expires = 0

if ( Request.Form+"." !="undefined.")
   { // ----------------------------------
     // Ya existe el formulario
     // ---------------------------------- 





   }
else	
   { // ----------------------------------
     // NO existe el formulario
     // ---------------------------------- 
	 if ( FN_ICU_CtrlPermisos(IDE_PAG_ASP_IRCA_ADMIN_EXP_AS,IDE_FUNC_EXPEDIENTES,IDE_OPE_CREAR,false)==RET_OK ) 
	    { 
		  crearFormulario();
        }
     else
        { // --------------------------
          // Usuario NO autorizado
	      // --------------------------
          FN_ICU_MsgNoAutorizado();
        }
   } 

%>

</body>
</html>
