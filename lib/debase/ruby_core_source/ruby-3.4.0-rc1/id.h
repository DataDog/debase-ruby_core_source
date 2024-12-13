/* DO NOT EDIT THIS FILE DIRECTLY */
/**********************************************************************

  id.h -

  $Author$
  created at: Sun Oct 19 21:12:51 2008

  Copyright (C) 2007 Koichi Sasada

**********************************************************************/

#ifndef RUBY_ID_H
#define RUBY_ID_H

enum ruby_id_types {
    RUBY_ID_STATIC_SYM  = 0x01,
    RUBY_ID_LOCAL       = 0x00,
    RUBY_ID_INSTANCE    = (0x01<<1),
    RUBY_ID_GLOBAL      = (0x03<<1),
    RUBY_ID_ATTRSET     = (0x04<<1),
    RUBY_ID_CONST       = (0x05<<1),
    RUBY_ID_CLASS       = (0x06<<1),
    RUBY_ID_JUNK        = (0x07<<1),
    RUBY_ID_INTERNAL    = RUBY_ID_JUNK,
    RUBY_ID_SCOPE_SHIFT = 4,
    RUBY_ID_SCOPE_MASK  = (~(~0U<<(RUBY_ID_SCOPE_SHIFT-1))<<1)
};

#define ID_STATIC_SYM  RUBY_ID_STATIC_SYM
#define ID_SCOPE_SHIFT RUBY_ID_SCOPE_SHIFT
#define ID_SCOPE_MASK  RUBY_ID_SCOPE_MASK
#define ID_LOCAL       RUBY_ID_LOCAL
#define ID_INSTANCE    RUBY_ID_INSTANCE
#define ID_GLOBAL      RUBY_ID_GLOBAL
#define ID_ATTRSET     RUBY_ID_ATTRSET
#define ID_CONST       RUBY_ID_CONST
#define ID_CLASS       RUBY_ID_CLASS
#define ID_JUNK        RUBY_ID_JUNK
#define ID_INTERNAL    RUBY_ID_INTERNAL

#define symIFUNC ID2SYM(idIFUNC)
#define symCFUNC ID2SYM(idCFUNC)

#define RUBY_TOKEN_DOT2 128
#define RUBY_TOKEN_DOT3 129
#define RUBY_TOKEN_BDOT2 130
#define RUBY_TOKEN_BDOT3 131
#define RUBY_TOKEN_UPLUS 132
#define RUBY_TOKEN_UMINUS 133
#define RUBY_TOKEN_POW 134
#define RUBY_TOKEN_CMP 135
#define RUBY_TOKEN_LSHFT 136
#define RUBY_TOKEN_RSHFT 137
#define RUBY_TOKEN_LEQ 138
#define RUBY_TOKEN_GEQ 139
#define RUBY_TOKEN_EQ 140
#define RUBY_TOKEN_EQQ 141
#define RUBY_TOKEN_NEQ 142
#define RUBY_TOKEN_MATCH 143
#define RUBY_TOKEN_NMATCH 144
#define RUBY_TOKEN_AREF 145
#define RUBY_TOKEN_ASET 146
#define RUBY_TOKEN_COLON2 147
#define RUBY_TOKEN_ANDOP 148
#define RUBY_TOKEN_OROP 149
#define RUBY_TOKEN_ANDDOT 150
#define RUBY_TOKEN(t) RUBY_TOKEN_##t

#define RUBY_TOKEN2ID_TYPE(tok, type) ((tok<<RUBY_ID_SCOPE_SHIFT)|type|RUBY_ID_STATIC_SYM)
#define TOKEN2LOCALID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_LOCAL)
#define TOKEN2INSTANCEID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_INSTANCE)
#define TOKEN2GLOBALID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_GLOBAL)
#define TOKEN2CONSTID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_CONST)
#define TOKEN2CLASSID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_CLASS)
#define TOKEN2ATTRSETID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_ATTRSET)

enum ruby_method_ids {
    idDot2 = RUBY_TOKEN(DOT2),
    idDot3 = RUBY_TOKEN(DOT3),
    idUPlus = RUBY_TOKEN(UPLUS),
    idUMinus = RUBY_TOKEN(UMINUS),
    idPow = RUBY_TOKEN(POW),
    idCmp = RUBY_TOKEN(CMP),
    idPLUS = '+',
    idMINUS = '-',
    idMULT = '*',
    idDIV = '/',
    idMOD = '%',
    idLTLT = RUBY_TOKEN(LSHFT),
    idGTGT = RUBY_TOKEN(RSHFT),
    idLT = '<',
    idLE = RUBY_TOKEN(LEQ),
    idGT = '>',
    idGE = RUBY_TOKEN(GEQ),
    idEq = RUBY_TOKEN(EQ),
    idEqq = RUBY_TOKEN(EQQ),
    idNeq = RUBY_TOKEN(NEQ),
    idNot = '!',
    idAnd = '&',
    idOr = '|',
    idBackquote = '`',
    idEqTilde = RUBY_TOKEN(MATCH),
    idNeqTilde = RUBY_TOKEN(NMATCH),
    idAREF = RUBY_TOKEN(AREF),
    idASET = RUBY_TOKEN(ASET),
    idCOLON2 = RUBY_TOKEN(COLON2),
    idANDOP = RUBY_TOKEN(ANDOP),
    idOROP = RUBY_TOKEN(OROP),
    idANDDOT = RUBY_TOKEN(ANDDOT),
    tPRESERVED_ID_BEGIN = 150,
    idNilP,
    idIncludeP,
    idNULL,
    idEmptyP,
    idEqlP,
    idRespond_to,
    idRespond_to_missing,
    idIFUNC,
    idCFUNC,
    id_core_set_method_alias,
    id_core_set_variable_alias,
    id_core_undef_method,
    id_core_define_method,
    id_core_define_singleton_method,
    id_core_set_postexe,
    id_core_hash_merge_ptr,
    id_core_hash_merge_kwd,
    id_core_raise,
    id_core_sprintf,
    id_debug_created_info,
    tPRESERVED_ID_END,

    /* LOCAL tokens {{{ */
    tTOKEN_LOCAL_BEGIN = tPRESERVED_ID_END-1,
    tMax,
    tMin,
    tHash,
    tFreeze,
    tInspect,
    tIntern,
    tObject_id,
    t__id__,
    tConst_added,
    tConst_missing,
    tMethodMissing,
    tMethod_added,
    tSingleton_method_added,
    tMethod_removed,
    tSingleton_method_removed,
    tMethod_undefined,
    tSingleton_method_undefined,
    tLength,
    tSize,
    tGets,
    tSucc,
    tEach,
    tProc,
    tLambda,
    tSend,
    t__send__,
    t__recursive_key__,
    tInitialize,
    tInitialize_copy,
    tInitialize_clone,
    tInitialize_dup,
    tTo_int,
    tTo_ary,
    tTo_str,
    tTo_sym,
    tTo_hash,
    tTo_proc,
    tTo_io,
    tTo_a,
    tTo_s,
    tTo_i,
    tTo_f,
    tTo_r,
    tBt,
    tBt_locations,
    tCall,
    tMesg,
    tException,
    tLocals,
    tNOT,
    tAND,
    tOR,
    tDiv,
    tDivmod,
    tFdiv,
    tQuo,
    tName,
    tNil,
    tPath,
    tPack,
    tBuffer,
    tUScore,
    tNUMPARAM_1,
    tNUMPARAM_2,
    tNUMPARAM_3,
    tNUMPARAM_4,
    tNUMPARAM_5,
    tNUMPARAM_6,
    tNUMPARAM_7,
    tNUMPARAM_8,
    tNUMPARAM_9,
    tDefault,
    tTOKEN_LOCAL_END,
    /* LOCAL tokens }}} */

    /* INSTANCE tokens {{{ */
    tTOKEN_INSTANCE_BEGIN = tTOKEN_LOCAL_END-1,
    tTOKEN_INSTANCE_END,
    /* INSTANCE tokens }}} */

    /* GLOBAL tokens {{{ */
    tTOKEN_GLOBAL_BEGIN = tTOKEN_INSTANCE_END-1,
    tLASTLINE,
    tBACKREF,
    tERROR_INFO,
    tTOKEN_GLOBAL_END,
    /* GLOBAL tokens }}} */

    /* CONST tokens {{{ */
    tTOKEN_CONST_BEGIN = tTOKEN_GLOBAL_END-1,
    tTOKEN_CONST_END,
    /* CONST tokens }}} */

    /* CLASS tokens {{{ */
    tTOKEN_CLASS_BEGIN = tTOKEN_CONST_END-1,
    tTOKEN_CLASS_END,
    /* CLASS tokens }}} */

    /* ATTRSET tokens {{{ */
    tTOKEN_ATTRSET_BEGIN = tTOKEN_CLASS_END-1,
    tTOKEN_ATTRSET_END,
    /* ATTRSET tokens }}} */

    tNEXT_ID = tTOKEN_ATTRSET_END,

    /* LOCAL IDs {{{ */
#define DEFINE_LOCALID_FROM_TOKEN(n) id##n = TOKEN2LOCALID(t##n)
    DEFINE_LOCALID_FROM_TOKEN(Max),
    DEFINE_LOCALID_FROM_TOKEN(Min),
    DEFINE_LOCALID_FROM_TOKEN(Hash),
    DEFINE_LOCALID_FROM_TOKEN(Freeze),
    DEFINE_LOCALID_FROM_TOKEN(Inspect),
    DEFINE_LOCALID_FROM_TOKEN(Intern),
    DEFINE_LOCALID_FROM_TOKEN(Object_id),
    DEFINE_LOCALID_FROM_TOKEN(__id__),
    DEFINE_LOCALID_FROM_TOKEN(Const_added),
    DEFINE_LOCALID_FROM_TOKEN(Const_missing),
    DEFINE_LOCALID_FROM_TOKEN(MethodMissing),
    DEFINE_LOCALID_FROM_TOKEN(Method_added),
    DEFINE_LOCALID_FROM_TOKEN(Singleton_method_added),
    DEFINE_LOCALID_FROM_TOKEN(Method_removed),
    DEFINE_LOCALID_FROM_TOKEN(Singleton_method_removed),
    DEFINE_LOCALID_FROM_TOKEN(Method_undefined),
    DEFINE_LOCALID_FROM_TOKEN(Singleton_method_undefined),
    DEFINE_LOCALID_FROM_TOKEN(Length),
    DEFINE_LOCALID_FROM_TOKEN(Size),
    DEFINE_LOCALID_FROM_TOKEN(Gets),
    DEFINE_LOCALID_FROM_TOKEN(Succ),
    DEFINE_LOCALID_FROM_TOKEN(Each),
    DEFINE_LOCALID_FROM_TOKEN(Proc),
    DEFINE_LOCALID_FROM_TOKEN(Lambda),
    DEFINE_LOCALID_FROM_TOKEN(Send),
    DEFINE_LOCALID_FROM_TOKEN(__send__),
    DEFINE_LOCALID_FROM_TOKEN(__recursive_key__),
    DEFINE_LOCALID_FROM_TOKEN(Initialize),
    DEFINE_LOCALID_FROM_TOKEN(Initialize_copy),
    DEFINE_LOCALID_FROM_TOKEN(Initialize_clone),
    DEFINE_LOCALID_FROM_TOKEN(Initialize_dup),
    DEFINE_LOCALID_FROM_TOKEN(To_int),
    DEFINE_LOCALID_FROM_TOKEN(To_ary),
    DEFINE_LOCALID_FROM_TOKEN(To_str),
    DEFINE_LOCALID_FROM_TOKEN(To_sym),
    DEFINE_LOCALID_FROM_TOKEN(To_hash),
    DEFINE_LOCALID_FROM_TOKEN(To_proc),
    DEFINE_LOCALID_FROM_TOKEN(To_io),
    DEFINE_LOCALID_FROM_TOKEN(To_a),
    DEFINE_LOCALID_FROM_TOKEN(To_s),
    DEFINE_LOCALID_FROM_TOKEN(To_i),
    DEFINE_LOCALID_FROM_TOKEN(To_f),
    DEFINE_LOCALID_FROM_TOKEN(To_r),
    DEFINE_LOCALID_FROM_TOKEN(Bt),
    DEFINE_LOCALID_FROM_TOKEN(Bt_locations),
    DEFINE_LOCALID_FROM_TOKEN(Call),
    DEFINE_LOCALID_FROM_TOKEN(Mesg),
    DEFINE_LOCALID_FROM_TOKEN(Exception),
    DEFINE_LOCALID_FROM_TOKEN(Locals),
    DEFINE_LOCALID_FROM_TOKEN(NOT),
    DEFINE_LOCALID_FROM_TOKEN(AND),
    DEFINE_LOCALID_FROM_TOKEN(OR),
    DEFINE_LOCALID_FROM_TOKEN(Div),
    DEFINE_LOCALID_FROM_TOKEN(Divmod),
    DEFINE_LOCALID_FROM_TOKEN(Fdiv),
    DEFINE_LOCALID_FROM_TOKEN(Quo),
    DEFINE_LOCALID_FROM_TOKEN(Name),
    DEFINE_LOCALID_FROM_TOKEN(Nil),
    DEFINE_LOCALID_FROM_TOKEN(Path),
    DEFINE_LOCALID_FROM_TOKEN(Pack),
    DEFINE_LOCALID_FROM_TOKEN(Buffer),
    DEFINE_LOCALID_FROM_TOKEN(UScore),
    DEFINE_LOCALID_FROM_TOKEN(NUMPARAM_1),
    DEFINE_LOCALID_FROM_TOKEN(NUMPARAM_2),
    DEFINE_LOCALID_FROM_TOKEN(NUMPARAM_3),
    DEFINE_LOCALID_FROM_TOKEN(NUMPARAM_4),
    DEFINE_LOCALID_FROM_TOKEN(NUMPARAM_5),
    DEFINE_LOCALID_FROM_TOKEN(NUMPARAM_6),
    DEFINE_LOCALID_FROM_TOKEN(NUMPARAM_7),
    DEFINE_LOCALID_FROM_TOKEN(NUMPARAM_8),
    DEFINE_LOCALID_FROM_TOKEN(NUMPARAM_9),
    DEFINE_LOCALID_FROM_TOKEN(Default),
#undef DEFINE_LOCALID_FROM_TOKEN
    /* LOCAL IDs }}} */

    /* INSTANCE IDs {{{ */
#define DEFINE_INSTANCEID_FROM_TOKEN(n) id##n = TOKEN2INSTANCEID(t##n)
#undef DEFINE_INSTANCEID_FROM_TOKEN
    /* INSTANCE IDs }}} */

    /* GLOBAL IDs {{{ */
#define DEFINE_GLOBALID_FROM_TOKEN(n) id##n = TOKEN2GLOBALID(t##n)
    DEFINE_GLOBALID_FROM_TOKEN(LASTLINE),
    DEFINE_GLOBALID_FROM_TOKEN(BACKREF),
    DEFINE_GLOBALID_FROM_TOKEN(ERROR_INFO),
#undef DEFINE_GLOBALID_FROM_TOKEN
    /* GLOBAL IDs }}} */

    /* CONST IDs {{{ */
#define DEFINE_CONSTID_FROM_TOKEN(n) id##n = TOKEN2CONSTID(t##n)
#undef DEFINE_CONSTID_FROM_TOKEN
    /* CONST IDs }}} */

    /* CLASS IDs {{{ */
#define DEFINE_CLASSID_FROM_TOKEN(n) id##n = TOKEN2CLASSID(t##n)
#undef DEFINE_CLASSID_FROM_TOKEN
    /* CLASS IDs }}} */

    /* ATTRSET IDs {{{ */
#define DEFINE_ATTRSETID_FROM_TOKEN(n) id##n = TOKEN2ATTRSETID(t##n)
#undef DEFINE_ATTRSETID_FROM_TOKEN
    /* ATTRSET IDs }}} */

    tLAST_OP_ID = tPRESERVED_ID_END-1,
    idLAST_OP_ID = tLAST_OP_ID >> ID_SCOPE_SHIFT
};

#endif /* RUBY_ID_H */
