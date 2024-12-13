/*----------------------------------------------------------------------------*/
/* This file is generated by the templates/template.rb script and should not  */
/* be modified manually. See                                                  */
/* templates/include/prism/diagnostic.h.erb                                   */
/* if you are looking to modify the                                           */
/* template                                                                   */
/*----------------------------------------------------------------------------*/

/**
 * @file diagnostic.h
 *
 * A list of diagnostics generated during parsing.
 */
#ifndef PRISM_DIAGNOSTIC_H
#define PRISM_DIAGNOSTIC_H

#include "prism/ast.h"
#include "prism/defines.h"
#include "prism/util/pm_list.h"

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
 * The diagnostic IDs of all of the diagnostics, used to communicate the types
 * of errors between the parser and the user.
 */
typedef enum {
    // These are the error diagnostics.
    PM_ERR_ALIAS_ARGUMENT,
    PM_ERR_ALIAS_ARGUMENT_NUMBERED_REFERENCE,
    PM_ERR_AMPAMPEQ_MULTI_ASSIGN,
    PM_ERR_ARGUMENT_AFTER_BLOCK,
    PM_ERR_ARGUMENT_AFTER_FORWARDING_ELLIPSES,
    PM_ERR_ARGUMENT_BARE_HASH,
    PM_ERR_ARGUMENT_BLOCK_FORWARDING,
    PM_ERR_ARGUMENT_BLOCK_MULTI,
    PM_ERR_ARGUMENT_CONFLICT_AMPERSAND,
    PM_ERR_ARGUMENT_CONFLICT_STAR,
    PM_ERR_ARGUMENT_CONFLICT_STAR_STAR,
    PM_ERR_ARGUMENT_FORMAL_CLASS,
    PM_ERR_ARGUMENT_FORMAL_CONSTANT,
    PM_ERR_ARGUMENT_FORMAL_GLOBAL,
    PM_ERR_ARGUMENT_FORMAL_IVAR,
    PM_ERR_ARGUMENT_FORWARDING_UNBOUND,
    PM_ERR_ARGUMENT_NO_FORWARDING_AMPERSAND,
    PM_ERR_ARGUMENT_NO_FORWARDING_ELLIPSES,
    PM_ERR_ARGUMENT_NO_FORWARDING_STAR,
    PM_ERR_ARGUMENT_NO_FORWARDING_STAR_STAR,
    PM_ERR_ARGUMENT_SPLAT_AFTER_ASSOC_SPLAT,
    PM_ERR_ARGUMENT_SPLAT_AFTER_SPLAT,
    PM_ERR_ARGUMENT_TERM_PAREN,
    PM_ERR_ARGUMENT_UNEXPECTED_BLOCK,
    PM_ERR_ARRAY_ELEMENT,
    PM_ERR_ARRAY_EXPRESSION,
    PM_ERR_ARRAY_EXPRESSION_AFTER_STAR,
    PM_ERR_ARRAY_SEPARATOR,
    PM_ERR_ARRAY_TERM,
    PM_ERR_BEGIN_LONELY_ELSE,
    PM_ERR_BEGIN_TERM,
    PM_ERR_BEGIN_UPCASE_BRACE,
    PM_ERR_BEGIN_UPCASE_TERM,
    PM_ERR_BEGIN_UPCASE_TOPLEVEL,
    PM_ERR_BLOCK_PARAM_LOCAL_VARIABLE,
    PM_ERR_BLOCK_PARAM_PIPE_TERM,
    PM_ERR_BLOCK_TERM_BRACE,
    PM_ERR_BLOCK_TERM_END,
    PM_ERR_CANNOT_PARSE_EXPRESSION,
    PM_ERR_CANNOT_PARSE_STRING_PART,
    PM_ERR_CASE_EXPRESSION_AFTER_CASE,
    PM_ERR_CASE_EXPRESSION_AFTER_WHEN,
    PM_ERR_CASE_MATCH_MISSING_PREDICATE,
    PM_ERR_CASE_MISSING_CONDITIONS,
    PM_ERR_CASE_TERM,
    PM_ERR_CLASS_IN_METHOD,
    PM_ERR_CLASS_NAME,
    PM_ERR_CLASS_SUPERCLASS,
    PM_ERR_CLASS_TERM,
    PM_ERR_CLASS_UNEXPECTED_END,
    PM_ERR_CLASS_VARIABLE_BARE,
    PM_ERR_CONDITIONAL_ELSIF_PREDICATE,
    PM_ERR_CONDITIONAL_IF_PREDICATE,
    PM_ERR_CONDITIONAL_PREDICATE_TERM,
    PM_ERR_CONDITIONAL_TERM,
    PM_ERR_CONDITIONAL_TERM_ELSE,
    PM_ERR_CONDITIONAL_UNLESS_PREDICATE,
    PM_ERR_CONDITIONAL_UNTIL_PREDICATE,
    PM_ERR_CONDITIONAL_WHILE_PREDICATE,
    PM_ERR_CONSTANT_PATH_COLON_COLON_CONSTANT,
    PM_ERR_DEF_ENDLESS,
    PM_ERR_DEF_ENDLESS_SETTER,
    PM_ERR_DEF_NAME,
    PM_ERR_DEF_PARAMS_TERM,
    PM_ERR_DEF_PARAMS_TERM_PAREN,
    PM_ERR_DEF_RECEIVER,
    PM_ERR_DEF_RECEIVER_TERM,
    PM_ERR_DEF_TERM,
    PM_ERR_DEFINED_EXPRESSION,
    PM_ERR_EMBDOC_TERM,
    PM_ERR_EMBEXPR_END,
    PM_ERR_EMBVAR_INVALID,
    PM_ERR_END_UPCASE_BRACE,
    PM_ERR_END_UPCASE_TERM,
    PM_ERR_ESCAPE_INVALID_CONTROL,
    PM_ERR_ESCAPE_INVALID_CONTROL_REPEAT,
    PM_ERR_ESCAPE_INVALID_HEXADECIMAL,
    PM_ERR_ESCAPE_INVALID_META,
    PM_ERR_ESCAPE_INVALID_META_REPEAT,
    PM_ERR_ESCAPE_INVALID_UNICODE,
    PM_ERR_ESCAPE_INVALID_UNICODE_CM_FLAGS,
    PM_ERR_ESCAPE_INVALID_UNICODE_LIST,
    PM_ERR_ESCAPE_INVALID_UNICODE_LITERAL,
    PM_ERR_ESCAPE_INVALID_UNICODE_LONG,
    PM_ERR_ESCAPE_INVALID_UNICODE_SHORT,
    PM_ERR_ESCAPE_INVALID_UNICODE_TERM,
    PM_ERR_EXPECT_ARGUMENT,
    PM_ERR_EXPECT_EOL_AFTER_STATEMENT,
    PM_ERR_EXPECT_EXPRESSION_AFTER_AMPAMPEQ,
    PM_ERR_EXPECT_EXPRESSION_AFTER_COMMA,
    PM_ERR_EXPECT_EXPRESSION_AFTER_EQUAL,
    PM_ERR_EXPECT_EXPRESSION_AFTER_LESS_LESS,
    PM_ERR_EXPECT_EXPRESSION_AFTER_LPAREN,
    PM_ERR_EXPECT_EXPRESSION_AFTER_OPERATOR,
    PM_ERR_EXPECT_EXPRESSION_AFTER_PIPEPIPEEQ,
    PM_ERR_EXPECT_EXPRESSION_AFTER_QUESTION,
    PM_ERR_EXPECT_EXPRESSION_AFTER_SPLAT,
    PM_ERR_EXPECT_EXPRESSION_AFTER_SPLAT_HASH,
    PM_ERR_EXPECT_EXPRESSION_AFTER_STAR,
    PM_ERR_EXPECT_FOR_DELIMITER,
    PM_ERR_EXPECT_IDENT_REQ_PARAMETER,
    PM_ERR_EXPECT_IN_DELIMITER,
    PM_ERR_EXPECT_LPAREN_REQ_PARAMETER,
    PM_ERR_EXPECT_MESSAGE,
    PM_ERR_EXPECT_RBRACKET,
    PM_ERR_EXPECT_RPAREN,
    PM_ERR_EXPECT_RPAREN_AFTER_MULTI,
    PM_ERR_EXPECT_RPAREN_REQ_PARAMETER,
    PM_ERR_EXPECT_SINGLETON_CLASS_DELIMITER,
    PM_ERR_EXPECT_STRING_CONTENT,
    PM_ERR_EXPECT_WHEN_DELIMITER,
    PM_ERR_EXPRESSION_BARE_HASH,
    PM_ERR_EXPRESSION_NOT_WRITABLE,
    PM_ERR_EXPRESSION_NOT_WRITABLE_ENCODING,
    PM_ERR_EXPRESSION_NOT_WRITABLE_FALSE,
    PM_ERR_EXPRESSION_NOT_WRITABLE_FILE,
    PM_ERR_EXPRESSION_NOT_WRITABLE_LINE,
    PM_ERR_EXPRESSION_NOT_WRITABLE_NIL,
    PM_ERR_EXPRESSION_NOT_WRITABLE_NUMBERED,
    PM_ERR_EXPRESSION_NOT_WRITABLE_SELF,
    PM_ERR_EXPRESSION_NOT_WRITABLE_TRUE,
    PM_ERR_FLOAT_PARSE,
    PM_ERR_FOR_COLLECTION,
    PM_ERR_FOR_IN,
    PM_ERR_FOR_INDEX,
    PM_ERR_FOR_TERM,
    PM_ERR_GLOBAL_VARIABLE_BARE,
    PM_ERR_HASH_EXPRESSION_AFTER_LABEL,
    PM_ERR_HASH_KEY,
    PM_ERR_HASH_ROCKET,
    PM_ERR_HASH_TERM,
    PM_ERR_HASH_VALUE,
    PM_ERR_HEREDOC_IDENTIFIER,
    PM_ERR_HEREDOC_TERM,
    PM_ERR_INCOMPLETE_QUESTION_MARK,
    PM_ERR_INCOMPLETE_VARIABLE_CLASS,
    PM_ERR_INCOMPLETE_VARIABLE_CLASS_3_3,
    PM_ERR_INCOMPLETE_VARIABLE_INSTANCE,
    PM_ERR_INCOMPLETE_VARIABLE_INSTANCE_3_3,
    PM_ERR_INSTANCE_VARIABLE_BARE,
    PM_ERR_INVALID_BLOCK_EXIT,
    PM_ERR_INVALID_CHARACTER,
    PM_ERR_INVALID_COMMA,
    PM_ERR_INVALID_ENCODING_MAGIC_COMMENT,
    PM_ERR_INVALID_ESCAPE_CHARACTER,
    PM_ERR_INVALID_FLOAT_EXPONENT,
    PM_ERR_INVALID_LOCAL_VARIABLE_READ,
    PM_ERR_INVALID_LOCAL_VARIABLE_WRITE,
    PM_ERR_INVALID_MULTIBYTE_CHAR,
    PM_ERR_INVALID_MULTIBYTE_CHARACTER,
    PM_ERR_INVALID_MULTIBYTE_ESCAPE,
    PM_ERR_INVALID_NUMBER_BINARY,
    PM_ERR_INVALID_NUMBER_DECIMAL,
    PM_ERR_INVALID_NUMBER_FRACTION,
    PM_ERR_INVALID_NUMBER_HEXADECIMAL,
    PM_ERR_INVALID_NUMBER_OCTAL,
    PM_ERR_INVALID_NUMBER_UNDERSCORE_INNER,
    PM_ERR_INVALID_NUMBER_UNDERSCORE_TRAILING,
    PM_ERR_INVALID_PERCENT,
    PM_ERR_INVALID_PERCENT_EOF,
    PM_ERR_INVALID_PRINTABLE_CHARACTER,
    PM_ERR_INVALID_RETRY_AFTER_ELSE,
    PM_ERR_INVALID_RETRY_AFTER_ENSURE,
    PM_ERR_INVALID_RETRY_WITHOUT_RESCUE,
    PM_ERR_INVALID_SYMBOL,
    PM_ERR_INVALID_VARIABLE_GLOBAL,
    PM_ERR_INVALID_VARIABLE_GLOBAL_3_3,
    PM_ERR_INVALID_YIELD,
    PM_ERR_IT_NOT_ALLOWED_NUMBERED,
    PM_ERR_IT_NOT_ALLOWED_ORDINARY,
    PM_ERR_LAMBDA_OPEN,
    PM_ERR_LAMBDA_TERM_BRACE,
    PM_ERR_LAMBDA_TERM_END,
    PM_ERR_LIST_I_LOWER_ELEMENT,
    PM_ERR_LIST_I_LOWER_TERM,
    PM_ERR_LIST_I_UPPER_ELEMENT,
    PM_ERR_LIST_I_UPPER_TERM,
    PM_ERR_LIST_W_LOWER_ELEMENT,
    PM_ERR_LIST_W_LOWER_TERM,
    PM_ERR_LIST_W_UPPER_ELEMENT,
    PM_ERR_LIST_W_UPPER_TERM,
    PM_ERR_MALLOC_FAILED,
    PM_ERR_MIXED_ENCODING,
    PM_ERR_MODULE_IN_METHOD,
    PM_ERR_MODULE_NAME,
    PM_ERR_MODULE_TERM,
    PM_ERR_MULTI_ASSIGN_MULTI_SPLATS,
    PM_ERR_MULTI_ASSIGN_UNEXPECTED_REST,
    PM_ERR_NESTING_TOO_DEEP,
    PM_ERR_NO_LOCAL_VARIABLE,
    PM_ERR_NON_ASSOCIATIVE_OPERATOR,
    PM_ERR_NOT_EXPRESSION,
    PM_ERR_NUMBER_LITERAL_UNDERSCORE,
    PM_ERR_NUMBERED_PARAMETER_INNER_BLOCK,
    PM_ERR_NUMBERED_PARAMETER_IT,
    PM_ERR_NUMBERED_PARAMETER_ORDINARY,
    PM_ERR_NUMBERED_PARAMETER_OUTER_BLOCK,
    PM_ERR_OPERATOR_MULTI_ASSIGN,
    PM_ERR_OPERATOR_WRITE_ARGUMENTS,
    PM_ERR_OPERATOR_WRITE_BLOCK,
    PM_ERR_PARAMETER_ASSOC_SPLAT_MULTI,
    PM_ERR_PARAMETER_BLOCK_MULTI,
    PM_ERR_PARAMETER_CIRCULAR,
    PM_ERR_PARAMETER_FORWARDING_AFTER_REST,
    PM_ERR_PARAMETER_METHOD_NAME,
    PM_ERR_PARAMETER_NAME_DUPLICATED,
    PM_ERR_PARAMETER_NO_DEFAULT,
    PM_ERR_PARAMETER_NO_DEFAULT_KW,
    PM_ERR_PARAMETER_NUMBERED_RESERVED,
    PM_ERR_PARAMETER_ORDER,
    PM_ERR_PARAMETER_SPLAT_MULTI,
    PM_ERR_PARAMETER_STAR,
    PM_ERR_PARAMETER_UNEXPECTED_FWD,
    PM_ERR_PARAMETER_UNEXPECTED_NO_KW,
    PM_ERR_PARAMETER_WILD_LOOSE_COMMA,
    PM_ERR_PATTERN_ARRAY_MULTIPLE_RESTS,
    PM_ERR_PATTERN_CAPTURE_DUPLICATE,
    PM_ERR_PATTERN_EXPRESSION_AFTER_BRACKET,
    PM_ERR_PATTERN_EXPRESSION_AFTER_COMMA,
    PM_ERR_PATTERN_EXPRESSION_AFTER_HROCKET,
    PM_ERR_PATTERN_EXPRESSION_AFTER_IN,
    PM_ERR_PATTERN_EXPRESSION_AFTER_KEY,
    PM_ERR_PATTERN_EXPRESSION_AFTER_PAREN,
    PM_ERR_PATTERN_EXPRESSION_AFTER_PIN,
    PM_ERR_PATTERN_EXPRESSION_AFTER_PIPE,
    PM_ERR_PATTERN_EXPRESSION_AFTER_RANGE,
    PM_ERR_PATTERN_EXPRESSION_AFTER_REST,
    PM_ERR_PATTERN_FIND_MISSING_INNER,
    PM_ERR_PATTERN_HASH_IMPLICIT,
    PM_ERR_PATTERN_HASH_KEY,
    PM_ERR_PATTERN_HASH_KEY_DUPLICATE,
    PM_ERR_PATTERN_HASH_KEY_INTERPOLATED,
    PM_ERR_PATTERN_HASH_KEY_LABEL,
    PM_ERR_PATTERN_HASH_KEY_LOCALS,
    PM_ERR_PATTERN_IDENT_AFTER_HROCKET,
    PM_ERR_PATTERN_LABEL_AFTER_COMMA,
    PM_ERR_PATTERN_REST,
    PM_ERR_PATTERN_TERM_BRACE,
    PM_ERR_PATTERN_TERM_BRACKET,
    PM_ERR_PATTERN_TERM_PAREN,
    PM_ERR_PIPEPIPEEQ_MULTI_ASSIGN,
    PM_ERR_REGEXP_ENCODING_OPTION_MISMATCH,
    PM_ERR_REGEXP_INCOMPAT_CHAR_ENCODING,
    PM_ERR_REGEXP_INVALID_UNICODE_RANGE,
    PM_ERR_REGEXP_NON_ESCAPED_MBC,
    PM_ERR_REGEXP_PARSE_ERROR,
    PM_ERR_REGEXP_TERM,
    PM_ERR_REGEXP_UNKNOWN_OPTIONS,
    PM_ERR_REGEXP_UTF8_CHAR_NON_UTF8_REGEXP,
    PM_ERR_RESCUE_EXPRESSION,
    PM_ERR_RESCUE_MODIFIER_VALUE,
    PM_ERR_RESCUE_TERM,
    PM_ERR_RESCUE_VARIABLE,
    PM_ERR_RETURN_INVALID,
    PM_ERR_SCRIPT_NOT_FOUND,
    PM_ERR_SINGLETON_FOR_LITERALS,
    PM_ERR_STATEMENT_ALIAS,
    PM_ERR_STATEMENT_POSTEXE_END,
    PM_ERR_STATEMENT_PREEXE_BEGIN,
    PM_ERR_STATEMENT_UNDEF,
    PM_ERR_STRING_CONCATENATION,
    PM_ERR_STRING_INTERPOLATED_TERM,
    PM_ERR_STRING_LITERAL_EOF,
    PM_ERR_STRING_LITERAL_TERM,
    PM_ERR_SYMBOL_INVALID,
    PM_ERR_SYMBOL_TERM_DYNAMIC,
    PM_ERR_SYMBOL_TERM_INTERPOLATED,
    PM_ERR_TERNARY_COLON,
    PM_ERR_TERNARY_EXPRESSION_FALSE,
    PM_ERR_TERNARY_EXPRESSION_TRUE,
    PM_ERR_UNARY_DISALLOWED,
    PM_ERR_UNARY_RECEIVER,
    PM_ERR_UNDEF_ARGUMENT,
    PM_ERR_UNEXPECTED_BLOCK_ARGUMENT,
    PM_ERR_UNEXPECTED_INDEX_BLOCK,
    PM_ERR_UNEXPECTED_INDEX_KEYWORDS,
    PM_ERR_UNEXPECTED_LABEL,
    PM_ERR_UNEXPECTED_MULTI_WRITE,
    PM_ERR_UNEXPECTED_RANGE_OPERATOR,
    PM_ERR_UNEXPECTED_SAFE_NAVIGATION,
    PM_ERR_UNEXPECTED_TOKEN_CLOSE_CONTEXT,
    PM_ERR_UNEXPECTED_TOKEN_IGNORE,
    PM_ERR_UNTIL_TERM,
    PM_ERR_VOID_EXPRESSION,
    PM_ERR_WHILE_TERM,
    PM_ERR_WRITE_TARGET_IN_METHOD,
    PM_ERR_WRITE_TARGET_READONLY,
    PM_ERR_WRITE_TARGET_UNEXPECTED,
    PM_ERR_XSTRING_TERM,

    // These are the warning diagnostics.
    PM_WARN_AMBIGUOUS_BINARY_OPERATOR,
    PM_WARN_AMBIGUOUS_FIRST_ARGUMENT_MINUS,
    PM_WARN_AMBIGUOUS_FIRST_ARGUMENT_PLUS,
    PM_WARN_AMBIGUOUS_PREFIX_AMPERSAND,
    PM_WARN_AMBIGUOUS_PREFIX_STAR,
    PM_WARN_AMBIGUOUS_PREFIX_STAR_STAR,
    PM_WARN_AMBIGUOUS_SLASH,
    PM_WARN_COMPARISON_AFTER_COMPARISON,
    PM_WARN_DOT_DOT_DOT_EOL,
    PM_WARN_EQUAL_IN_CONDITIONAL,
    PM_WARN_EQUAL_IN_CONDITIONAL_3_3,
    PM_WARN_END_IN_METHOD,
    PM_WARN_DUPLICATED_HASH_KEY,
    PM_WARN_DUPLICATED_WHEN_CLAUSE,
    PM_WARN_FLOAT_OUT_OF_RANGE,
    PM_WARN_IGNORED_FROZEN_STRING_LITERAL,
    PM_WARN_INDENTATION_MISMATCH,
    PM_WARN_INTEGER_IN_FLIP_FLOP,
    PM_WARN_INVALID_CHARACTER,
    PM_WARN_INVALID_MAGIC_COMMENT_VALUE,
    PM_WARN_INVALID_NUMBERED_REFERENCE,
    PM_WARN_KEYWORD_EOL,
    PM_WARN_LITERAL_IN_CONDITION_DEFAULT,
    PM_WARN_LITERAL_IN_CONDITION_VERBOSE,
    PM_WARN_SHAREABLE_CONSTANT_VALUE_LINE,
    PM_WARN_SHEBANG_CARRIAGE_RETURN,
    PM_WARN_UNEXPECTED_CARRIAGE_RETURN,
    PM_WARN_UNREACHABLE_STATEMENT,
    PM_WARN_UNUSED_LOCAL_VARIABLE,
    PM_WARN_VOID_STATEMENT,
} pm_diagnostic_id_t;

/**
 * This struct represents a diagnostic generated during parsing.
 *
 * @extends pm_list_node_t
 */
typedef struct {
    /** The embedded base node. */
    pm_list_node_t node;

    /** The location of the diagnostic in the source. */
    pm_location_t location;

    /** The ID of the diagnostic. */
    pm_diagnostic_id_t diag_id;

    /** The message associated with the diagnostic. */
    const char *message;

    /**
     * Whether or not the memory related to the message of this diagnostic is
     * owned by this diagnostic. If it is, it needs to be freed when the
     * diagnostic is freed.
     */
    bool owned;

    /**
     * The level of the diagnostic, see `pm_error_level_t` and
     * `pm_warning_level_t` for possible values.
     */
    uint8_t level;
} pm_diagnostic_t;

/**
 * The levels of errors generated during parsing.
 */
typedef enum {
    /** For errors that should raise a syntax error. */
    PM_ERROR_LEVEL_SYNTAX = 0,

    /** For errors that should raise an argument error. */
    PM_ERROR_LEVEL_ARGUMENT = 1,

    /** For errors that should raise a load error. */
    PM_ERROR_LEVEL_LOAD = 2
} pm_error_level_t;

/**
 * The levels of warnings generated during parsing.
 */
typedef enum {
    /** For warnings which should be emitted if $VERBOSE != nil. */
    PM_WARNING_LEVEL_DEFAULT = 0,

    /** For warnings which should be emitted if $VERBOSE == true. */
    PM_WARNING_LEVEL_VERBOSE = 1
} pm_warning_level_t;

/**
 * Get the human-readable name of the given diagnostic ID.
 *
 * @param diag_id The diagnostic ID.
 * @return The human-readable name of the diagnostic ID.
 */
const char * pm_diagnostic_id_human(pm_diagnostic_id_t diag_id);

/**
 * Append a diagnostic to the given list of diagnostics that is using shared
 * memory for its message.
 *
 * @param list The list to append to.
 * @param start The start of the diagnostic.
 * @param end The end of the diagnostic.
 * @param diag_id The diagnostic ID.
 * @return Whether the diagnostic was successfully appended.
 */
bool pm_diagnostic_list_append(pm_list_t *list, const uint8_t *start, const uint8_t *end, pm_diagnostic_id_t diag_id);

/**
 * Append a diagnostic to the given list of diagnostics that is using a format
 * string for its message.
 *
 * @param list The list to append to.
 * @param start The start of the diagnostic.
 * @param end The end of the diagnostic.
 * @param diag_id The diagnostic ID.
 * @param ... The arguments to the format string for the message.
 * @return Whether the diagnostic was successfully appended.
 */
bool pm_diagnostic_list_append_format(pm_list_t *list, const uint8_t *start, const uint8_t *end, pm_diagnostic_id_t diag_id, ...);

/**
 * Deallocate the internal state of the given diagnostic list.
 *
 * @param list The list to deallocate.
 */
void pm_diagnostic_list_free(pm_list_t *list);

#endif
