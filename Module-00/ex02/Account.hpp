/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:01:50 by revieira          #+#    #+#             */
/*   Updated: 2023/10/18 16:50:29 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_H
# define ACCOUNT_H

#include <iostream>

class Account
{
	public:
		Account();
		Account(int amount);
		~Account();
		typedef Account	t;

		int			getIndex(void);
		int			getAmount(void);
		int			getDeposits(void);
		int			getWithdrawals(void);

		int			getNumberAccounts(void);
		int			getTotalAmount(void);
		int			getTotalDeposits(void);
		int			getTotalWithdrawals(void);

		void		setIndex(int index);
		void		setAmount(int amount);
		void		setDeposits(int deposit);
		void		setWithdrawals(int withdrawals);
		
		static void	displayAccountsInfos(void);
		void		displayStatus(void);
		void		makeDeposit(int deposit);
		void		makeWithdrawal(int withdrawal);

	private:
		int	_index;
		int	_amount;
		int	_deposits;
		int	_withdrawals;
		static int	_nbAccounts;
		static int	_totalAmount;
		static int	_totalDeposits;
		static int	_totalWithdrawals;
};

#endif
