write_template('transaction_type_' .. (...), {
   typename = 'TransactionType',
   param = 'type',
   constants = {
      'deferred',
      'immediate',
      'exclusive'
   }
})
