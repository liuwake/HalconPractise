/*****************************************************************************
 * HOperator.h
 ***************************************************************************** 
 *
 * Project:     Halcon
 * Creation:    
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef HOPERATOR_H
#define HOPERATOR_H


namespace Halcon {


class LIntExport HOperator {
public:
  HOperator(char *op_name);
  HOperator(const HOperator &op);
  HOperator &operator = (const HOperator &op);
  ~HOperator();
  
  void SetInputObject(const char *param_name, const Hobject &obj);
  void SetInputObject(int param_num, const Hobject &obj);

  const Hobject &GetOutputObject(const char *param_name) const;
  const Hobject &GetOutputObject(int param_num) const;

  void SetInputCtrl(const char *param_name, const HTuple &val);
  void SetInputCtrl(int param_num, const HTuple &val);

  const HTuple &GetOutputCtrl(const char *param_name) const;
  const HTuple &GetOutputCtrl(int param_num) const;

  Herror Execute ();
  
  const Hobject* GetInpObj() const { return _inp_obj; }
  const Hobject* GetOutpObj() const { return _outp_obj; }
  const HTuple* GetInpCtrl() const { return _inp_ctrl; }
  const HTuple* GetOutpCtrl() const { return _outp_ctrl; }

  int GetInpObjNumber() const { return _inp_obj_num; }
  int GetOutpObjNumber() const { return _outp_obj_num; }
  int GetInpCtrlNumber() const { return _inp_ctrl_num; }
  int GetOutpCtrlNumber() const { return _outp_ctrl_num; }

  const char* GetOperatorName() const { return _op_name; }
  int GetOperatorNumber() const { return _op_num; }

private:
  Hobject _inp_obj[MAX_INP_OBJ_PAR];
  Hobject _outp_obj[MAX_OUTP_OBJ_PAR];
  HTuple _inp_ctrl[MAX_INP_CTRL_PAR];
  HTuple _outp_ctrl[MAX_OUTP_CTRL_PAR];      
  HTuple _inp_obj_names, _outp_obj_names, _inp_ctrl_names, _outp_ctrl_names;  
  int _inp_obj_num, _outp_obj_num, _inp_ctrl_num, _outp_ctrl_num;
  char *_op_name;
  int  _op_num;

  void CopyOperator (const HOperator&);
  int Search_Number(const char* param_name, const HTuple& aTuple) const;
};


}


#endif
